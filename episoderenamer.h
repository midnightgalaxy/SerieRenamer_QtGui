#ifndef EPISODERENAMER_H
#define EPISODERENAMER_H

#include <string>

class EpisodeRenamer
{
public:
    EpisodeRenamer(std::string & pathInp, std::string & nameInp, std::string & seasonInp, std::string & fileTypeInp, std::string & extraInp);
    EpisodeRenamer(std::string & pathInp, std::string & nameInp, std::string & seasonInp, std::string & fileTypeInp);
    void execute();
    std::string getInformationOutput();

private:
    std::string path;
    std::string name;
    std::string season;
    std::string extra;
    bool extraInfo;
    std::string fileType;

    std::string informationOutput;
};

#endif // EPISODERENAMER_H
