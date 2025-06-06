#include "PicPlayer.h"

PicPlayer::PicPlayer(QWidget *parent)
	: QMainWindow(parent), m_currentDrawImageIndx(0)
{
	ui.setupUi(this);

    // 添加ImageOpacity属性;
    this->setProperty("ImageOpacity", 1.0);
    // 动画切换类;
    m_opacityAnimation = new QPropertyAnimation(this, "ImageOpacity");
    // 这里要设置的动画时间小于图片切换时间;
    m_opacityAnimation->setDuration(1500);
    // 设置ImageOpacity属性值的变化范围;
    m_opacityAnimation->setStartValue(1.0);
    m_opacityAnimation->setEndValue(0.0);
    // 透明度变化及时更新绘图;
    connect(m_opacityAnimation, SIGNAL(valueChanged(const QVariant&)), this, SLOT(update()));
    // 设置图片切换时钟槽函数;
    connect(&m_imageChangeTimer, SIGNAL(timeout()), this, SLOT(onImageChangeTimeout()));
    //this->setFixedSize(QSize(400, 250));
    this->setWindowFlags(Qt::FramelessWindowHint);
}

PicPlayer::~PicPlayer()
{}

void PicPlayer::initChangeImageButton()
{
    // 注意图片过多按钮可能放置不下;
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
    // 添加完图片之后，根据图片多少设置图片切换按钮;
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

void PicPlayer::stopPlay()
{
    m_imageChangeTimer.stop();
}

void PicPlayer::startPlayAgain()
{
    m_imageChangeTimer.start(2000);
}

void PicPlayer::onImageChangeTimeout()
{
    // 设置前后的图片;
    m_currentPixmap = QPixmap(m_imageFileNameList.at(m_currentDrawImageIndx));
    m_currentDrawImageIndx++;
    if (m_currentDrawImageIndx >= m_imageFileNameList.count())
    {
        m_currentDrawImageIndx = 0;
    }
    m_nextPixmap = QPixmap(m_imageFileNameList.at(m_currentDrawImageIndx));
    m_pButtonChangeImageList[m_currentDrawImageIndx]->setChecked(true);
    // 动画类重新开始;
    m_opacityAnimation->start();
}
void PicPlayer::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);//绘制样式

    QBitmap bmp(this->size());
    bmp.fill();
    QPainter painter(&bmp);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    //设置边框为圆角12px
    painter.drawRoundedRect(bmp.rect(), 12, 12);
    setMask(bmp);
    QWidget::paintEvent(event);

    QPainter painter1(this);
    QRect imageRect = this->rect();
    // 如果图片列表为空，显示默认图片;
    if (m_imageFileNameList.isEmpty())
    {
        QPixmap backPixmap = QPixmap(":/Resources/CarouselImageBack.png");
        painter1.drawPixmap(imageRect, backPixmap.scaled(imageRect.size()));
    }
    // 如果只有一张图片;
    else if (m_imageFileNameList.count() == 1)
    {
        QPixmap backPixmap = QPixmap(m_imageFileNameList.first());
        painter1.drawPixmap(imageRect, backPixmap.scaled(imageRect.size()));
    }
    // 多张图片;
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
    // 这里可以对当前图片进行点击然后触发每个图片对应的效果;
    // 比如web上好多类似的弹出对应的广告页面等功能;
    qDebug() << m_currentDrawImageIndx;
    return __super::mousePressEvent(event);
}
