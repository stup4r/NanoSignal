/*************************************************************************
 *
 *  NanoSignal: Signal analysis toolbox.
 *  Copyright (C) 2017  Petar Stupar
 *  Collective Copyright Holder.
 *  Licensed under the GPLv3.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ************************************************************************/

#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>

/**
 * @brief designSplash Designs a splash screen.
 * Function calls up a flash screen with animated logo. It actually takes a set of photos and shows them in a particular order to create an animation effect.
 */
void designSplash(){
    QString name = ":/new/prefix1/Splash/a";
    QStringList fileNames;
    for(int i=1; i<16; i++)
    {
        fileNames << (name+QString("%1").arg(i));
    }
    QSplashScreen *splashScreen = new QSplashScreen(QPixmap(":/new/prefix1/Splash/a15.png"));
    splashScreen->show();
    QTime finishingTime = QTime::currentTime().addSecs(4);
    int count = 0;
    while(QTime::currentTime()<=finishingTime)
    {
        if(count>14){
          splashScreen->setPixmap(QPixmap(":/new/prefix1/Splash/a15.png"));
        }
        else{
          splashScreen->setPixmap(QPixmap(fileNames[count]));
          QThread::msleep(100);
        }
        count++;
    }
    splashScreen->hide();
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv); /**< Application API */
    System system; /**< Data manager */
    MainWindow w; /**< Application Window */

    designSplash();

    w.setSystem(&system);
    w.show();

    return a.exec();
}
