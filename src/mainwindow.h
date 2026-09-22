#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class is the main application window. Among other
 * things, it handles the inputs from the screen widgets.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  Ui::MainWindow *ui;

  explicit MainWindow(QWidget *parent = nullptr);
  void renderToFile();
  ~MainWindow() override;

 private slots:
  void on_ResetRotationButton_clicked(bool checked);
  void on_RotationDialX_valueChanged(int value);
  void on_RotationDialY_valueChanged(int value);
  void on_RotationDialZ_valueChanged(int value);

  void on_ResetScaleButton_clicked(bool checked);
  void on_ScaleSlider_valueChanged(int value);

  void on_PhongButton_toggled(bool checked);
  void on_NormalButton_toggled(bool checked);
  void on_GouraudButton_toggled(bool checked);
};

#endif  // MAINWINDOW_H
