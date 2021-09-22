# ScreenTime [only supports on windows 10 or above]
Desktop application for monitoring screen activity.


## Table of Contents
- [Pre-requisites](#prerequisites)
- [Running it Locally](#running-it-locally)
- [Project Status](#project-status)
- [Youe First PR](#your-first-pr)

### Pre-requisites
If you want to setup and run the application in your host os.
- Visual Studio 2019 and above
- MYSQL

### Running it Locally
1. Install MYSQL connector and Server 
1. Create a database and table 
```
    CREATE DATABASE screentimedb;
```
2. Create a table of name `screentime`
```
    CREATE TABLE screentime ( 
        id INT NOT NULL AUTO_INCREMENT,
        process_name VARCHAR(255) NULL DEFAULT NULL,
        process_path VARCHAR(255) NOT NULL,
        window_title VARCHAR(255) NOT NULL,
        start_date_time VARCHAR(255) NOT NULL,
        end_date_time VARCHAR(255) NULL DEFAULT NULL,
        time_diff VARCHAR(255) NOT NULL DEFAULT '0',
        PRIMARY KEY (id)
    ) 
    ENGINE = InnoDB;
```
3. Build executable and run `.exe`
4. ✨ Now the magic will begin ✨

### Project Status
[x] Monitors screen time - when and app is opened & closed and gains and loses focus.
[x] Supported on Windows 10 and above.
[ ] Github action for CI/CD.
[ ] Generate screen time report for users.
[ ] ISSUE and a PR template.

### Your First PR
Contribution is always welcome, either PR or an ISSUE.
