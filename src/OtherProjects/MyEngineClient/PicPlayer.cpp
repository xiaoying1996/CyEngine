#include "PicPlayer.h"

PicPlayer::PicPlayer(QWidget *parent)
	: QMainWindow(parent), m_currentDrawImageIndx(0)
{
	ui.setupUi(this);

    // ���ImageOpacity����;
    this->setProperty("ImageOpacity", 1.0);
    // �����л���;
    m_opacityAnimation = new QPropertyAnimation(this, "ImageOpacity");
    // ����Ҫ���õĶ���ʱ��С��ͼƬ�л�ʱ��;
    m_opacityAnimation->setDuration(1500);
    // ����ImageOpacity����ֵ�ı仯��Χ;
    m_opacityAnimation->setStartValue(1.0);
    m_opacityAnimation->setEndValue(0.0);
    // ͸���ȱ仯��ʱ���»�ͼ;
    connect(m_opacityAnimation, SIGNAL(valueChanged(const QVariant&)), this, SLOT(update()));
    // ����ͼƬ�л�ʱ�Ӳۺ���;
    connect(&m_imageChangeTimer, SIGNAL(timeout()), this, SLOT(onImageChangeTimeout()));
    //this->setFixedSize(QSize(400, 250));
    this->setWindowFlags(Qt::FramelessWindowHint);
}

PicPlayer::~PicPlayer()
{}

void PicPlayer::initChangeImageButton()
{
    // ע��ͼƬ���ఴť���ܷ��ò���;
    QButtonGroup* changeButtonGroup = new QButtonGroup;
    QHBoxLayout* hLayout = new QHBoxLayout();
    hLayout->addStretch();
    for (int i = 0; i < m_imageFileNameList.count(); i++)
    {
        QPushButton* pButton = new QPushButton;
        pButton->setFixedSize(QSize(16, 16));
        pButton->setCheckable(true);
        pButton->setStyleSheet("QPushButton{border-image:url(:/Resources/select1.png);}\QPushButton:checked{border-image:url(:/Resources/select2.png);}");
        changeButtonGroup->addButton(pButton, i);
        m_pButtonChangeImageList.append(pButton);
        hLayout->addWidget(pButton);
    }
    hLayout->addStretch();
    hLayout->setSpacing(10);
    hLayout->setMargin(0);
    connect(changeButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(onImageSwitchButtonClicked(int)));
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(hLayout);
    mainLayout->setContentsMargins(0, 0, 0, 20);
}

void PicPlayer::setImageList(QStringList imageFileNameList)
{
    m_imageFileNameList = imageFileNameList;
}

void PicPlayer::addImage(QString imageFileName)
{
    m_imageFileNameList.append(imageFileName);
}
void PicPlayer::startPlay()
{
    // �����ͼƬ֮�󣬸���ͼƬ��������ͼƬ�л���ť;
    initChangeImageButton();
    if (m_imageFileNameList.count() == 1)
    {
        m_pButtonChangeImageList[m_currentDrawImageIndx]->setChecked(true);
    }
    else if (m_imageFileNameList.count() > 1)
    {
        m_pButtonChangeImageList[m_currentDrawImageIndx]->setChecked(true);
        m_currentPixmap = QPixmap(m_imageFileNameList.at(m_currentDrawImageIndx));
        m_imageChangeTimer.start(2000);
        update();
    }
}
void PicPlayer::onImageChangeTimeout()
{
    // ����ǰ���ͼƬ;
    m_currentPixmap = QPixmap(m_imageFileNameList.at(m_currentDrawImageIndx));
    m_currentDrawImageIndx++;
    if (m_currentDrawImageIndx >= m_imageFileNameList.count())
    {
        m_currentDrawImageIndx = 0;
    }
    m_nextPixmap = QPixmap(m_imageFileNameList.at(m_currentDrawImageIndx));
    m_pButtonChangeImageList[m_currentDrawImageIndx]->setChecked(true);
    // ���������¿�ʼ;
    m_opacityAnimation->start();
}
void PicPlayer::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);//������ʽ

    QBitmap bmp(this->size());
    bmp.fill();
    QPainter painter(&bmp);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    //���ñ߿�ΪԲ��12px
    painter.drawRoundedRect(bmp.rect(), 12, 12);
    setMask(bmp);
    QWidget::paintEvent(event);

    QPainter painter1(this);
    QRect imageRect = this->rect();
    // ���ͼƬ�б�Ϊ�գ���ʾĬ��ͼƬ;
    if (m_imageFileNameList.isEmpty())
    {
        QPixmap backPixmap = QPixmap(":/Resources/CarouselImageBack.png");
        painter1.drawPixmap(imageRect, backPixmap.scaled(imageRect.size()));
    }
    // ���ֻ��һ��ͼƬ;
    else if (m_imageFileNameList.count() == 1)
    {
        QPixmap backPixmap = QPixmap(m_imageFileNameList.first());
        painter1.drawPixmap(imageRect, backPixmap.scaled(imageRect.size()));
    }
    // ����ͼƬ;
    else if (m_imageFileNameList.count() > 1)
    {
        float imageOpacity = this->property("ImageOpacity").toFloat();
        painter1.setOpacity(1);
        painter1.drawPixmap(imageRect, m_nextPixmap.scaled(imageRect.size()));
        painter1.setOpacity(imageOpacity);
        painter1.drawPixmap(imageRect, m_currentPixmap.scaled(imageRect.size()));
    }
}
void PicPlayer::onImageSwitchButtonClicked(int buttonId)
{
    m_currentDrawImageIndx = buttonId - 1;
    if (m_currentDrawImageIndx == -1)
    {
        m_currentDrawImageIndx = m_imageFileNameList.count() - 1;
    }
    onImageChangeTimeout();
    m_imageChangeTimer.start(2000);
    update();
}
void PicPlayer::mousePressEvent(QMouseEvent* event)
{
    // ������ԶԵ�ǰͼƬ���е��Ȼ�󴥷�ÿ��ͼƬ��Ӧ��Ч��;
    // ����web�Ϻö����Ƶĵ�����Ӧ�Ĺ��ҳ��ȹ���;
    qDebug() << m_currentDrawImageIndx;
    return __super::mousePressEvent(event);
}
