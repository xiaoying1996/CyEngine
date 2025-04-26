#include "MyEngineClient.h"
#include <QIcon>

MyEngineClient::MyEngineClient(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("登录"));
    QIcon icon("material/pic/login/title2.png");
    this->setWindowIcon(icon);

    m_picPlayer = new PicPlayer(this);
    m_picPlayer->move(450,20);
    m_picPlayer->resize(430, 560);
    m_picPlayer->addImage("material/pic/login/pic1.jpg");
    m_picPlayer->addImage("material/pic/login/pic2.jpg");
    m_picPlayer->addImage("material/pic/login/pic3.jpg");
    m_picPlayer->addImage("material/pic/login/pic4.jpg");
    m_picPlayer->addImage("material/pic/login/pic5.jpg");
    m_picPlayer->startPlay();

    QString filename("material/pic/login/logo.png");
    QImage* img = new QImage;
    if (!(img->load(filename))) //加载图像
    {
        QMessageBox::information(this,
            tr("打开图像失败"),
            tr("打开图像失败!"));
        delete img;
        return;
    }
    ui.label_2->setPixmap(QPixmap::fromImage(*img));
    ui.label_2->setFixedSize(this->width() / 2, this->height() / 2); //设置label大小
    ui.label_2->setScaledContents(true); //将pixmap图自适应填充到label

    ui.AccountBox->setEditable(true);

    //初始化TCP客户端
    MyTcpClient::GetInstance();
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slot_ProcessTimeout()));
    m_timer->start(100);

    ui.PasswordEdit->setEchoMode(QLineEdit::Password);
}

MyEngineClient::~MyEngineClient()
{
    if (m_picPlayer != nullptr)
    {
        m_picPlayer->close();
        delete m_picPlayer;
    }
    if (m_signup != nullptr)
    {
        m_signup->close();
        delete m_signup;
    }
    MyTcpClient::deleteInstance();
}

void MyEngineClient::on_SignUpBtn_clicked()
{
    bool con;
    MyTcpClient::GetInstance()->GetConnectState(con);
    if (!con)
    {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未连接服务器"), QMessageBox::Close);
        return;
    }
    if (m_signup == nullptr)
    {
        m_signup = new SignUpWidget();
    }
    m_signup->show();
    connect(m_signup, SIGNAL(sig_closed()), this, SLOT(slot_SignUpCLosed()));
    m_picPlayer->stopPlay();
    this->hide();
}

void MyEngineClient::on_SignInBtn_clicked()
{
    MainMessage m_Login;
    Login_Request* message = new Login_Request();
    m_Login.set_type(LOGIN_REQUEST);
    message->set_name(ui.AccountBox->currentText().toStdString());
    message->set_password(ui.PasswordEdit->text().toStdString());
    m_Login.set_allocated_content9(message);
    std::string msgStr = "";
    if (m_Login.SerializeToString(&msgStr))
        //qDebug() << QString::fromLocal8Bit("序列化后的str") << QString::fromStdString(msgStr) + "\n";
        m_Login.clear_content9();
    m_Login.Clear();
    MyTcpClient::GetInstance()->SendMessage(msgStr);
}

void MyEngineClient::slot_ProcessTimeout()
{
    QVector<std::string> strs;
    MyTcpClient::GetInstance()->GetRetStrs(strs);
    if (strs.size())
    {
        for (int i = 0; i < strs.size(); i++)
        {
            std::string str = strs[i];
            MainMessage protoMsg;
            protoMsg.ParseFromString(str);
            MessageType type = protoMsg.type();
            if (protoMsg.type() == MessageType::NAME_REPEAT_REPOST)//关于用户名是否重复的消息
            {
                Name_Repeat_Repost content = protoMsg.content2();
                bool res = content.state();
                m_signup->SetUserNameRepeatState(res);
            }
            if (protoMsg.type() == MessageType::NUMBER_REPEAT_REPOST)//关于手机号码是否重复
            {
                Number_Repeat_Repost content = protoMsg.content4();
                bool res = content.state();
                m_signup->SetNumberRepeatState(res);
            }
            if (protoMsg.type() == MessageType::EMAIL_REPEAT_REPOST)//关于手机号码是否重复
            {
                Email_Repeat_Repost content = protoMsg.content6();
                bool res = content.state();
                m_signup->SetEmailRepeatState(res);
            }
            if (protoMsg.type() == MessageType::REGISTER_REPOST)
            {
                Register_Repost content = protoMsg.content8();
                bool res = content.state();
                m_signup->ShowRegister(res);
            }
            if (protoMsg.type() == MessageType::LOGIN_REPOST)
            {
                Login_Repost content = protoMsg.content10();
                bool res = content.state();
                if (res)
                {
                    if (m_HCL == nullptr)
                    {
                        m_HCL = new HCLWidhet();
                        m_HCL->show();
                        //创建客户端主界面并将用户名赋值给主界面
                        content.name();
                        this->hide();
                    }
                }
            }
        }
    }
}

void MyEngineClient::slot_SignUpCLosed()
{
    this->show();
    m_signup->close();
    delete m_signup;
    m_signup = nullptr;
}