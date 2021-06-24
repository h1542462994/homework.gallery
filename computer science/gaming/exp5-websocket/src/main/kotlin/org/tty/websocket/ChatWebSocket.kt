

package org.tty.websocket

import java.lang.Exception
import javax.websocket.*
import javax.websocket.server.ServerEndpoint

@ServerEndpoint("/chat")
class ChatWebSocket {
    private var id: String = ""
    private lateinit var task: Thread

    @OnOpen
    fun onOpen(session: Session) {
        this.id = session.id
        println("新连接: $id")

        task = Thread {
            try {
                while (true) {
                    if (session.isOpen) {
                        Thread.sleep(5000)
                        val message = "服务器发送的消息"
                        session.basicRemote.sendText(message)
                    }
                }
            } catch (e: Exception) {
                e.printStackTrace()
            }

        }

        task.start()
    }

    @OnClose
    fun onClose() {
        println("连接关闭: $id")
        task.interrupt()
    }

    @OnMessage
    fun onMessage(message: String, session: Session) {
        println("收到用户${id}的消息${message}")
        session.basicRemote.sendText("收到${id}的消息:${message}")
    }

    @OnError
    fun onError(session: Session, error: Throwable) {
        println("用户id为${id}的连接发生错误")
        error.printStackTrace()
    }
}