#include "applicationutils.h"

QUndoStack ApplicationUtils::undoStack;

ApplicationUtils::ApplicationUtils()
{
}

QUndoStack &ApplicationUtils::getUndoStack()
{
    return ApplicationUtils::undoStack;
}
