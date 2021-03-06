#ifndef IDISTRIBUTION_H
#define IDISTRIBUTION_H

#include "distrostruct.h"
#include "envirement.h"
#include "templateinfo.h"
#include <QProcess>

#include <QFileInfo>
class FileManager;
class DistroModule;
class PackageControl;

class DEPLOYSHARED_EXPORT iDistribution
{
public:
    iDistribution(FileManager * fileManager);
    virtual ~iDistribution();

    virtual bool deployTemplate(PackageControl& pkgCtrl) = 0;
    virtual bool removeTemplate() const = 0;
    virtual Envirement toolKitEnv() const = 0;
    virtual QProcessEnvironment processEnvirement() const = 0;

    virtual QString runCmd() = 0;
    virtual QStringList runArg() const = 0;
    virtual QStringList outPutFiles() const = 0;

    QString getClassName() const;

protected:
    QString getLocation() const;
    void setLocation(const QString &location);
    bool unpackFile(const QFileInfo& resource,
                    const QString& target,
                    const TemplateInfo& info,
                    const QStringList &sufixes) const;

    bool unpackDir(const QString& resource,
                   const QString& target,
                   const TemplateInfo& info,
                   const QStringList &sufixes) const;

    bool moveData(const QString& from, const QString& to, const QString &ignore) const;
    bool copyFile(const QString& from, const QString& to, bool isFileTarget) const;
    bool copyDir(const QString &resource, const QString &target) const;

    void registerOutFiles() const;

private:

    QString _location = "Temp Template";
    FileManager * _fileManager = nullptr;

};

#endif // IDISTRIBUTION_H
