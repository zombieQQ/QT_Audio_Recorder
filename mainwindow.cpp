#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AudioRecorder = new QAudioRecorder(this);
//    durationChanged信号携带了一个duration参数，表示从录音开始到当前的总时长，这里链接到MainWindow 的"updateProgress"槽
//    这个connect函数调用设置了当AudioRecorder的durationChanged信号被触发时，自动调用MainWindow的updateProgress槽函数，并将duration作为参数传递。
    connect(AudioRecorder,&QAudioRecorder::durationChanged,this,&MainWindow::updateProgress);

    AudioProbe = new QAudioProbe(this);
    AudioProbe->setSource(AudioRecorder);

    QAudioEncoderSettings Settings;
    Settings.setCodec("audio/pcm");
    Settings.setSampleRate(0);
    Settings.setBitRate(0);
    Settings.setChannelCount(-1);
    Settings.setQuality(QMultimedia::EncodingQuality::VeryHighQuality);
    Settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);
    QString Container = "audio/x-way"; //"audio/x-raw" (Option - 2)

    AudioRecorder->setOutputLocation(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/QtWithZom.wav"));
    //AudioRecorder->setEncodingSetting(Settings, QVideoEncoderSettings(), Container);
    AudioRecorder->setEncodingSettings(Settings, QVideoEncoderSettings(), Container);
}

//析构函数负责清理UI组件，避免内存泄漏。
MainWindow::~MainWindow()
{
    delete ui;
}

//控制录音的开始和停止。根据ISRecordingStart状态变量的值，切换录音状态，并更新按钮文字提示用户当前状态。
void MainWindow::on_pushButton_Start_Stop_Recording_clicked()
{
    if(ISRecordingStart == false){
//      这行代码开始音频录制。一旦录音开始，QAudioRecorder会持续跟踪已录制的音频长度，并在每次录音长度更新时发射durationChanged信号。
//      每次durationChanged信号发射时，updateProgress槽函数就会被调用，并带有最新的duration值。
        AudioRecorder->record();
        ISRecordingStart = true;
        ui->pushButton_Start_Stop_Recording->setText("Stop");
    }
    else{
        AudioRecorder->stop();
        ISRecordingStart = false;
        ui->pushButton_Start_Stop_Recording->setText("Start");

    }
}


void MainWindow::updateProgress(qint64 duration)
{
//    这段代码首先检查是否存在录音错误或录音时长是否少于1000毫秒（即1秒）。
//    这是通过检查AudioRecorder对象的error()方法返回的值是否不等于QMediaRecorder::NoError来判断的。如果有错误发生，或者录音时间还不足1秒，函数将执行return语句，
//    即提前结束并不执行后面的代码。这种检查是为了确保只有在有效录音且时间足够时，才更新界面上的显示。
    if(AudioRecorder->error() != QMediaRecorder::NoError || duration <1000)
        return;

    ui->label_Duration->setText("Recorded Audio Time Is :" +QString::number (duration / 1000 ) + " S ");
}
