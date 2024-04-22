#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

//MainWindow类继承自QMainWindow。
//Q_OBJECT宏在类定义中是必需的，它启用了Qt的元对象系统，包括信号和槽机制等功能。
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//  explicit: 这是一个C++关键字，用于防止构造函数进行隐式类型转换。在这里，它告诉编译器这个构造函数只能显式地使用，避免因意外类型转换而造成的潜在错误。
//  MainWindow: 这是构造函数的名称，与类名相同。
//  QWidget *parent = 0: 构造函数接受一个参数parent，类型为QWidget*。这个参数是一个指向父窗口的指针，
//  允许这个MainWindow类的实例关联到一个父窗口。默认值是0（在新的C++标准中通常写作nullptr），
//  意味着如果不提供父窗口，MainWindow的实例将默认没有父窗口。这在窗口层级中定义了该窗口作为顶级窗口的行为。
    ~MainWindow();
//  ~MainWindow(): 这是析构函数，用于清理在MainWindow对象生命周期结束时需要释放的资源。
//  析构函数在对象被销毁时自动调用，比如当窗口关闭时，或者包含MainWindow的对象被删除时。
//  符号~表示这是一个析构函数，其名称与类名相同，前面加上~表示它是用来进行析构（即清理工作）的特殊成员函数。

//  这段代码定义了MainWindow类中的两个私有槽（slots）。在Qt框架中，槽是特殊的函数，可以响应信号。
//  信号和槽机制是Qt中实现事件驱动编程的核心。下面是对这两个槽函数的详细解释：
private slots:
//  这个槽函数用来响应录音按钮，当用户点击界面上的录音按钮（pushButton_Start_Stop_Recording）时，该函数被调用
    void on_pushButton_Start_Stop_Recording_clicked();
//  这个槽函数用于更新录音的进度，在这更新显示已录制的时间qint64 duration 是传递给槽函数的参数，表示录音的持续时间
//  数据类型qint64是Qt中用于表示64位整数的类型。
//  这个参数可能用来计算并显示录音已进行的具体时间或更新进度条的状态。
    void updateProgress(qint64 duration);

private:
//  Ui::MainWindow *ui 是一个指针，指向由Qt Designer生成的界面类。
//  Ui::MainWindow是自动生成的类，用于表示由.ui文件定义的界面。
//  这个类包含了所有在Qt Designer中创建的控件的引用。
//  ui 用于在代码中访问和操作这些界面控件，如按钮、文本框等。
    Ui::MainWindow *ui;

//  QAudioRecorder *AudioRecorder 是一个指向QAudioRecorder对象的指针。QAudioRecorder是QtMultimedia模块中用于处理音频录制的类。
//  这个对象负责管理音频录制的所有方面，包括设备的选择、配置音频编码设置、控制录音的开始和停止等。
    QAudioRecorder *AudioRecorder;
//    QAudioProbe *AudioProbe 是一个指向QAudioProbe对象的指针。QAudioProbe是用来监听音频流并从中提取音频样本的类。
//    它可以被附加到QAudioRecorder或其他音频流产生器上，允许程序获取实时音频数据，这可能用于实时音频级别显示、波形生成或进行音频分析等。
    QAudioProbe *AudioProbe;
//    bool ISRecordingStart 是一个布尔类型的成员变量，用来记录录音的状态——是否已经开始录音。
//    初始值设为false，表示默认情况下，启动程序时并未进行录音。这个变量可能在点击开始录音按钮时被设置为true，并在停止录音或录音完成时被设置回false。
//    通过这个状态变量，程序可以在尝试停止录音或开始新的录音时做出适当的响应，确保录音操作的逻辑正确性。
    bool ISRecordingStart = false;
};

#endif // MAINWINDOW_H
