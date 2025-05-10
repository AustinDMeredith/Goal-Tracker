#ifndef PROG_STORAGE_H
#define PROG_STORAGE_H
#include <map>
#include <string>
#include "progressLog.h"

class ProgStorage {
private:
    std::map<std::string, ProgressLog> progLogs;

public:
    void addLog(const std::string& id, const ProgressLog& progLog);
    void updateLog(const std::string& id, const ProgressLog& updatedLog);
    void removeLog(const std::string& id);
    void writeToFile() const;

    ProgressLog* findLog(const std::string& id);

};

#endif