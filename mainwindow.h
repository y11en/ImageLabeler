#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "canvas.h"
#include "labeldialog.h"
#include "labelmanager.h"
#include "filemanager.h"
#include <QMainWindow>
#include <QMap>
#include <QLabel>
#include <QComboBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getCurrentLabel();

public slots:
    void reportMouseMoved(QPoint pos);
    void reportCanvasMode(QString mode);

    void zoomRequest(qreal delta, QPoint pos);
    void adjustFitWindow();

    void getNewRect(QRect rect);
    void getNewStrokes(const QList<SegStroke> &strokes);

    void newLabelRequest(QString newLabel);
    void removeLabelRequest(QString label);
    void provideLabelContextMenu(const QPoint &pos);
    void provideAnnoContextMenu(const QPoint &pos);

    bool switchFile(int idx);

private slots:
    void on_actionOpen_File_triggered();
    void on_actionOpen_Dir_triggered();
    void on_actionClose_triggered();

    void on_actionSave_triggered();
    void on_actionSave_As_triggered();

    void on_actionPrevious_Image_triggered();
    void on_actionNext_Image_triggered();
    void on_actionLoad_triggered();

    //    void on_actionExit_triggered();

    void on_actionZoom_in_triggered();
    void on_actionZoom_out_triggered();
    //    void on_actionAbout_triggered();

    qreal scaleFitWindow();

    void enableFileActions();
    void unableFileActions();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;

    LabelManager labelManager;
    AnnotationContainer annoContainer;

    FileManager fileManager;

    QLabel *mousePosLabel;
    QComboBox *taskComboBox;

    void _loadJsonFile(QString fileName);
    bool _checkUnsaved();

};

#endif // MAINWINDOW_H
