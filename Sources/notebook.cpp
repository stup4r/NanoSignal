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

#include "notebook.h"

Notebook::Notebook(){

}

Notebook::~Notebook(){

}

void Notebook::setTextEdit(QTextEdit* someTextEdit){
    this->notebookTextEdit = someTextEdit;
}

/**
 * @brief Notebook::extractPlot Extracts the plot from the plotting widget into the notebook.
 * @param plt Plotting widget pointer parsed from the main window
 * @param w width of the extracted graph in the notebook - user defined
 * @param h height of the extracted graph in the notebook - user defined
 */
void Notebook::extractPlot(QCustomPlot* plt, double w, double h){
    QTextCursor cursor = notebookTextEdit->textCursor();
    cursor.insertText(QString(QChar::ObjectReplacementCharacter), QCPDocumentObject::generatePlotFormat(plt, w, h));

    notebookTextEdit->setTextCursor(cursor);
}

/**
 * @brief Notebook::extractSettings Extracts parameters used in the signal processing.
 * @param params Parameters map that contains all the parameters and their values used.
 */
void Notebook::extractSettings(std::map<std::string, int>& params){
    QTextCursor cursor = notebookTextEdit->textCursor();
    QDateTime datetime = QDateTime::currentDateTime();

    cursor.insertText("------ Parameter Extraction ------\nTime of analysis: " + datetime.toString());

    QString extract;
    extract = "\nSampling Frequency: " + QString::number(params["samplingFreq"]) + " Hz";

    extract += "\n--- Flattening ---";
    if (params["isFlattening"] == 1) {
        if (params["flatWindowed"] == 1){
            extract += "\nChosen order: " + QString::number(params["flatOrder"]);
            extract += "\nWindow size: " + QString::number(params["flatWin"]) + " (" + QString::number(params["flatWin"]/params["samplingFreq"]) + "s)";
        }
        else extract += "\nNo windowing applied. Chosen order: " + QString::number(params["flatOrder"]);
    }
    else extract += "\n- Not applied.";

    extract += "\n--- Filtering ---";
    if (params["isFiltering"] == 1) {
        extract += "\nWindow size: " + QString::number(params["filtWin"]) + " (" + QString::number(params["filtWin"]/params["samplingFreq"]) + "s)";
    }
    else extract += "\n- Not applied.";

    extract += "\n--- Variance ---";
    extract += "\nWindow size: " + QString::number(params["varWin"]) + " (" + QString::number(params["varWin"]/params["samplingFreq"]) + "s)";

    cursor.insertText(extract);

    cursor.insertText("\n-------------------------------\n\n");
}

/**
 * @brief Notebook::saveNotebook Export of the notebook by printing it to the PDF file.
 * @param fileName Selected filename for a notebook PDF file.
 */
void Notebook::saveNotebook(QString& fileName){
    if (!fileName.isEmpty())
    {
      QPrinter printer;
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName(fileName);
      QMargins pageMargins(20, 20, 20, 20);
  #if QT_VERSION < QT_VERSION_CHECK(5, 3, 0)
      printer.setFullPage(false);
      printer.setPaperSize(QPrinter::A4);
      printer.setOrientation(QPrinter::Portrait);
      printer.setPageMargins(pageMargins.left(), pageMargins.top(), pageMargins.right(), pageMargins.bottom(), QPrinter::Millimeter);
  #else
      QPageLayout pageLayout;
      pageLayout.setMode(QPageLayout::StandardMode);
      pageLayout.setOrientation(QPageLayout::Portrait);
      pageLayout.setPageSize(QPageSize(QPageSize::A4));
      pageLayout.setUnits(QPageLayout::Millimeter);
      pageLayout.setMargins(QMarginsF(pageMargins));
      printer.setPageLayout(pageLayout);
  #endif
      notebookTextEdit->document()->setPageSize(printer.pageRect().size());
      notebookTextEdit->document()->print(&printer);
    }
}

void Notebook::clearNotes(){
    notebookTextEdit->clear();
}
