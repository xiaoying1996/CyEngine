#include "CyMapEditer.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>

CyMapEditer::CyMapEditer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("地图编辑器"));
    _saveAction = new QAction(QString("Save"), this);
    _saveAction->setShortcut(QKeySequence::Save);
    connect(_saveAction, &QAction::triggered, this, &CyMapEditer::slot_Save);

    // 添加到菜单（可选）
   /* QMenu* fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(_saveAction);*/

    // 添加到工具栏（可选）
    QToolBar* fileToolBar = addToolBar(tr("文件"));
    fileToolBar->addAction(_saveAction);
}

CyMapEditer::~CyMapEditer()
{}

void CyMapEditer::on_NewMapBtn_clicked()
{
    _GraphicsViewExample = new GraphicsViewExample(ui.MapWidget);
    if (_GraphicsViewExample)
    {
        _GraphicsViewExample->resize(ui.MapWidget->width() - 20, ui.MapWidget->height() - 20);
        _GraphicsViewExample->show();

        m_cube = new CubeItem(150.0f);
    }
}

void CyMapEditer::slot_Save()
{
    // 打开保存对话框
    QString fileName = QFileDialog::getSaveFileName(
        this,
        QString::fromLocal8Bit("保存文件"),
        QDir::homePath(),
        QString::fromLocal8Bit("所有文件 (*.*);;文本文件 (*.txt);;图像文件 (*.png *.jpg)")
    );

    if (!fileName.isEmpty()) {
        // 在这里实现保存逻辑
        qDebug() << "保存到:" << fileName;

        // 示例：保存文本到文件
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "需要保存的内容";
            file.close();

            QMessageBox::information(this, "保存成功", QStringLiteral("Save Success\n"));
        }
    }
}
