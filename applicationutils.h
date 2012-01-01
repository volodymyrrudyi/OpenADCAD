#ifndef APPLICATIONUTILS_H
#define APPLICATIONUTILS_H

#include <QUndoCommand>
#include <QUndoStack>

class ApplicationUtils
{
private:
    static QUndoStack undoStack;
public:
    ApplicationUtils();

    static QUndoStack &getUndoStack();

};

#endif // APPLICATIONUTILS_H
