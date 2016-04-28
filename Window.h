#ifndef WINDOW_H
#define WINDOW_H

#include <QEvent>
#include <QObject>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QString>

namespace redtimer {

class Window : public QQuickView
{
    Q_OBJECT

private:
    /// Emit the closed signal upon closing
    bool emitClosedSignal_ = true;

protected:
    /// Main item
    QQuickItem* item_;

    /// Window context
    QQmlContext* ctx_;

public:
    /**
     * @brief Window constructor for a window from a QML file within a Qt resource file
     *
     * @param qml Path to the QML file within the Qt resouce file
     * @param parent Parent QObject
     */
    Window( QString qml, QQuickView* parent = nullptr );

    /**
     * @brief Get a QML GUI item
     *
     * @param qmlItem Name of the QML GUI item
     *
     * @return QML GUI item
     */
    QQuickItem* qml( QString qmlItem );

protected:
    /**
     * @brief Filter Qt events
     *
     * Emits the canceled signal when window has been closed.
     *
     * @param event Received event
     *
     * @return true if event has been processed, false otherwise
     */
    bool event( QEvent* event );

public slots:
    /**
     * @brief Display a message
     *
     * @param text Message to display
     * @param type Message type (one of \c QtInfoMsg, \c QtWarningMsg and \c QtCriticalMsg)
     * @param timeout Duration in milliseconds that the message will be displayed
     */
    void message( QString text, QtMsgType type = QtInfoMsg, int timeout = 5000 );

signals:
    /**
     * @brief Signal that will be emitted when closing the window
     *
     * This signal will be emitted only once.
     */
    void closed();
};

} // redtimer

#endif // WINDOW_H