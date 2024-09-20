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
    if (m_signup == nullptr)
    {
        m_signup = new SignUpWidget();
    }
    m_signup->show();
}