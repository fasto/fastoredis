#include "shell/redis_shell.h"

#include <QKeyEvent>
#include <QMenu>

#include "common/macros.h"

#include "shell/redis_lexer.h"

#include "gui/gui_factory.h"

namespace fastoredis
{
    const QColor RedisShell::paperColor = QColor(166, 190, 233);

    RedisShell::RedisShell(QWidget *parent)
        : FastoEditor(parent)
    {
        RedisLexer* red = new RedisLexer(this);
        registerImage(RedisLexer::Command, GuiFactory::instance().redisCommandIcon().pixmap(QSize(64,64)));
        registerImage(RedisLexer::Types, GuiFactory::instance().redisTypeIcon().pixmap(QSize(64,64)));

        setLexer(red);
        red->setPaper(paperColor);

        setAutoCompletionThreshold(1);
        setAutoCompletionSource(QsciScintilla::AcsAPIs);
        setAutoCompletionCaseSensitivity(false);

        VERIFY(connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenu(const QPoint &))));
    }

    void RedisShell::showContextMenu(const QPoint &pt)
    {
        QMenu *menu = createStandardContextMenu();
        menu->exec(mapToGlobal(pt));
        delete menu;
    }

    void RedisShell::keyPressEvent(QKeyEvent *keyEvent)
    {
        if((keyEvent->modifiers() & Qt::ControlModifier) && (keyEvent->key() == Qt::Key_Return) ){
            emit executed();
        }

        return FastoEditor::keyPressEvent(keyEvent);
    }
}

