#include "xmlcomponentloader.h"

#include <iostream>
using namespace std;

XmlComponentLoader::XmlComponentLoader()
{

}

XmlComponentLoader::XmlComponentLoader(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)){
        if (!this->library.setContent(&file)){
            file.close();

        } else {

            QDomElement root = library.documentElement();

            if (root.tagName() != "library"){
                throw new QString("Selected file is not a library");
            }

            // TODO: add more general code and implement factory to create components
            if (root.attribute("type") != "principal"){
                throw new QString("Selected library is not a principal component library");
            }

            this->author =
                    (root.attribute("author"));
            this->description =
                    ( root.attribute("description"));
            this->componentTypes =
                    GetType(root.attributes().namedItem("type").nodeValue());


        }
    } else throw new QString("File not found");


}

ComponentType XmlComponentLoader::GetType(QString typeId)
{
    if (typeId == "block"){
        return BlockSchemeComponent;
    } else if (typeId == "principal"){
        return PrincipalSchemeComponent;
    } else  {
        return BoardSchemeComponent;
    }
}

void XmlComponentLoader::loadComponents()
{

    QDomNode node = library.firstChild().firstChild();

    while (!node.isNull()){
        cout << node.nodeName().toStdString();
        if (node.nodeName() == "component")
        {
            QMap<QString, QVariant> properties;

            QDomNode paramNode = node.firstChild();
            while (!paramNode.isNull())
            {
                if (paramNode.nodeName() == "parameter")
                {
                    properties.insert(
                            paramNode.attributes().namedItem("name").nodeValue(),
                            paramNode.attributes().namedItem("default").nodeValue()
                            );
                }

                paramNode = paramNode.nextSibling();

            }



            ComponentInfo info(
                    node.attributes().namedItem("name").nodeValue(),
                    this->componentTypes,
                    properties);

            this->components.push_back(info);

        }

        node = node.nextSibling();
    }


}

void XmlComponentLoader::freeComponents()
{

}

QString XmlComponentLoader::getAuthor() const
{
    return this->author;
}

QString XmlComponentLoader::getDescription() const
{
    return this->description;
}

ComponentType XmlComponentLoader::getComponentsType() const
{
    return this->componentTypes;
}
