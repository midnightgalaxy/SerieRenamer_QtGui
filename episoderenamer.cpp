#include <QDir>
#include <QDirIterator>

#include "episoderenamer.h"

EpisodeRenamer::EpisodeRenamer(std::string & pathInp, std::string & nameInp, std::string & seasonInp, std::string & fileTypeInp, std::string & extraInp)
{
    path = pathInp;
    name = nameInp;
    season = "S";
    season += seasonInp;
    fileType = fileTypeInp;
    extra = extraInp;
    extraInfo = true;

    informationOutput = "";
}

EpisodeRenamer::EpisodeRenamer(std::string & pathInp, std::string & nameInp, std::string & seasonInp, std::string & fileTypeInp)
{
    path = pathInp;
    name = nameInp;
    season = "S";
    season += seasonInp;
    fileType = fileTypeInp;
    extra = "";
    extraInfo = false;

    informationOutput = "";
}

void EpisodeRenamer::execute()
{
    QDir workPath(path.c_str());

    if (workPath.exists()) {
        int episodeCount = 1;
        QDirIterator it(workPath, QDirIterator::Subdirectories);
        while (it.hasNext())
        {
            QFileInfo tmp(it.next());

            if (tmp.isFile()) {
                QFile tmp2 (tmp.absoluteFilePath());

                QString fileRename;
                fileRename.append(tmp.absolutePath());
                fileRename.append("/");

                QString fileRenamePreview;
                fileRenamePreview.append(name.c_str());
                fileRenamePreview.append(".");
                fileRenamePreview.append(season.c_str());
                fileRenamePreview.append("E");
                if (episodeCount <= 9) {
                    fileRenamePreview.append("0");
                }
                fileRenamePreview.append(std::to_string(episodeCount).c_str());
                if (extraInfo == true) {
                    fileRenamePreview.append(".");
                    fileRenamePreview.append(extra.c_str());
                }
                fileRenamePreview.append(".");
                fileRenamePreview.append(fileType.c_str());

                fileRename.append((fileRenamePreview));

                informationOutput += "Renamed: ";
                informationOutput += tmp.absoluteFilePath().toStdString();
                informationOutput += " -> ";
                informationOutput += fileRenamePreview.toStdString();
                informationOutput += "\n";

                tmp2.rename(fileRename);

                episodeCount++;
            }
        }
        if (episodeCount == 1) {
            informationOutput += "Season ";
            informationOutput += season;
            informationOutput += " - No files to rename!\n";
        } else {
            informationOutput += "Season ";
            informationOutput += season;
            informationOutput += " - Done!\n";
        }

    } else {
        informationOutput += "Season ";
        informationOutput += season;
        informationOutput += " - Workpath didn't existed!\n";
    }
}

std::string EpisodeRenamer::getInformationOutput()
{
    return informationOutput;
}

