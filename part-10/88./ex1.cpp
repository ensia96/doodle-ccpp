// q3. 상속과 가상 함수를 사용해 중복되는 코드를 줄여 보세요.

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

enum LogLevels { // enum = 상수를 만드는 요소, 아래 명시된 순서대로 0번부터 숫자 값을 가지게 됨
    DEBUG,       // 디버깅을 목적으로 남기는 기록
    INFO,        // 로딩 시작, 로드 완료 등의 간단한 정보에 대한 안내
    WARNING,     // 경고
    ERROR,       // 오류
    FATAL        // 프로그램을 더이상 실행시킬 수 없을 정도의 치명적인 오류 등
};

const char* const LEVEL_HEADINGS[] = { // 로그 단계에 해당하는 로그 수준을 문자열로 저장해둔 배열
    "DEBUG", "INFO", "WARNING", "ERROR", "FATAL"
};

/*
class FileLogger { // 로그 파일을 만드는 역할을 함
                   // -> 프로그램 실행 과정에서 생기는 일들에 대한 기록을 로그라고 함
                   // -> 기록을 남기는 것은 로깅이라고 함
                   // -> 이런 기록을 파일이나 콘솔에 로깅할 수 있음
public:
    FileLogger(int minLevel, const string& fileName)
        : minLevel(minLevel)
    {
        logFile = fopen(fileName.c_str(), "a"); // fopen == 인자로 주어진 위치에 있는 파일에 대한 스트림을 반환
    }
    ~FileLogger()
    {
        fclose(logFile);
    }

    void Log(const string& s, int level)
    {
        if (level >= minLevel)
            fprintf(logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
            // 스트림이 가리키고 있는 파일에 로그 출력
            // -> 파일이 없던 상태에서 프로그램을 실행하면, 파일이 생성됨
            // -> 그리고, 그 파일에 내용이 출력됨
    }

    int GetMinLevel() const { return minLevel; }

private:
    int minLevel;
    FILE* logFile; // 스트림(파일을 가리키는 포인터)
};

class ConsoleLogger { // 콘솔에 로그를 남기는 역할을 함
public:
    ConsoleLogger(int minLevel)
        : minLevel(minLevel)
    {
    }

    void Log(const string& s, int level) // s = 로그 메시지, level = 로그 단계
    {
        if (level >= minLevel)                                     // 최소 로그 단계보다 로그 단계가 높은 로그라면 로깅
            printf("[%s] %s\n", LEVEL_HEADINGS[level], s.c_str()); // [로그 수준] 어떤 일이 벌어졌는지에 대한 메시지
                                                                   // c_str() = C 스타일 문자열로 변환해주는 메서드
                                                                   // -> C 스타일의 문자열 == char* s; == char s[];
    }

    int GetMinLevel() const { return minLevel; }

private:
    int minLevel; // 실제로 로깅을 할 최소의 로그 단계
};

int main()
{
    ConsoleLogger c(LogLevels::WARNING); // LogLevels::WARNING 대신 WARNING 또는 2로 써도 됨
                                         // -> 범위 확인 연산자(::) 로 변수 소속 범위를 지정해주지 않아도 됨
                                         // -> 그냥 가독성을 위해 이렇게 작성
                                         // -> 객체를 생성할 때 경고 수준의 로그 단계를 인자로 넘겨줌
                                         // -> 경고 수준 이상의 로그에 대해서 로깅을 하도록 지정해주는 것임
    c.Log("abc", LogLevels::ERROR);
    c.Log("def", LogLevels::INFO); // 경고 수준 이하의 로그이므로 기록이 남지 않음
    c.Log("ghi", LogLevels::WARNING);

    FileLogger f(LogLevels::DEBUG, "log.txt");
    f.Log("abc", LogLevels::ERROR);
    f.Log("def", LogLevels::INFO);
    f.Log("ghi", LogLevels::WARNING);
}
*/

/*
class Logger {
public:
    Logger(int minLevel)
        : minLevel(minLevel)
    {
    }
    virtual void Log(const string& s, int level) {};
    virtual int GetMinLevel() const { return minLevel; };
    bool CheckLevel(const int level) { return level >= minLevel; }
    string GetLog(const string& s, int level)
    {
        return "[" + (string)LEVEL_HEADINGS[level] + "] " + s.c_str() + "\n";
    }

private:
    int minLevel;
};

class FileLogger : public Logger {
public:
    FileLogger(int minLevel, const string& fileName)
        : Logger(minLevel)
    {
        logFile = fopen(fileName.c_str(), "a");
    }
    ~FileLogger()
    {
        fclose(logFile);
    }

    void Log(const string& s, int level)
    {
        if (Logger::CheckLevel(level))
            fprintf(logFile, "%s", Logger::GetLog(s, level).c_str());
    }

private:
    FILE* logFile;
};

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(int minLevel)
        : Logger(minLevel)
    {
    }

    void Log(const string& s, int level)
    {
        if (Logger::CheckLevel(level))
            cout << Logger::GetLog(s, level);
    }
};

int main()
{
    Logger* loggers[] = { new ConsoleLogger(LogLevels::WARNING), new FileLogger(LogLevels::DEBUG, "log.txt") };

    for (Logger* logger : loggers) {
        logger->Log("abc", LogLevels::ERROR);
        logger->Log("def", LogLevels::INFO);
        logger->Log("ghi", LogLevels::WARNING);
    }

    for (Logger* logger : loggers) {
        delete logger;
    }
}
*/

// int minLevel, void Log() 등이 중복됨
// -> 단, Log() 메서드의 경우, 서로 동작하는 방식이 살짝 다름
// -> 가상 함수를 만든 후 오버라이딩을 해도 됨

class Logger {
public:
    // 최소 로깅 단계 초기화를 Logger 클래스에서 진행
    // -> 파생 클래스에서는 기본 생성자가 없다는 오류가 뜰 것임 => Logger() {}
    // -> 생성자 위임을 통해 해결할 수 있음
    // -> 기본 생성자를 새로 선언하지 않아도 됨
    Logger(int minLevel)
        : minLevel(minLevel)
    {
    }
    /*
    Logger* l = new FileLogger(LogLevels::DEBUG, "log.txt");
    delete l;
    // 이렇게 사용하게 될 수도 있음
    // -> 가상 소멸자를 선언해줘야 함
    */
    virtual ~Logger() {};

    /*
    // 중복되는 메서드들을 메서드로 선언
    virtual void Log(const string& s, int level) = 0;
    */

    // Log() 메서드에서 로깅 조건을 확인하는 부분이 중복됨
    // -> 로깅 조건 확인을 부모 클래스에서 처리하도록 하면 더 깔끔해질 것임
    // -> Log() 메서드를 순수 가상 함수로 선언하지 않는 편이 더 좋음
    // -> Log() 메서드를 일반 메서드로 선언하는 대신, 로그 작업 자체를 가상 함수로 만들 것임
    // -> 로깅 조건을 부모 클래스에서 한 번에 처리할 수 있다는 것이 장점임
    void Log(const string& s, int level)
    {
        if (level >= minLevel) {
            doLogJob(s, level);
        }
    }

    int GetMinLevel() const { return minLevel; }

protected:
    int minLevel;

    virtual void doLogJob(const string& s, int level) = 0; // 로그 작업을 담당하는 메서드
};

class FileLogger : public Logger {
public:
    FileLogger(int minLevel, const string& fileName)
        : Logger(minLevel)
    {
        logFile = fopen(fileName.c_str(), "a");
    }
    ~FileLogger()
    {
        fclose(logFile);
    }

protected:
    void doLogJob(const string& s, int level)
    {
        fprintf(logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
    }

private:
    FILE* logFile;
};

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(int minLevel)
        : Logger(minLevel)
    {
    }

protected:
    void doLogJob(const string& s, int level)
    {
        printf("[%s] %s\n", LEVEL_HEADINGS[level], s.c_str());
    }
};

/*
int main()
{
    ConsoleLogger c(LogLevels::WARNING);
    c.Log("abc", LogLevels::ERROR);
    c.Log("def", LogLevels::INFO);
    c.Log("ghi", LogLevels::WARNING);

    FileLogger f(LogLevels::DEBUG, "log.txt");
    f.Log("abc", LogLevels::ERROR);
    f.Log("def", LogLevels::INFO);
    f.Log("ghi", LogLevels::WARNING);
}
*/

/*
// q4. 아래와 같은 상황에서 기존의 함수 작성하기 (오버로딩 x)
void testLogger()
{
}

int main()
{
    ConsoleLogger c(LogLevels::WARNING);
    testLogger(c);

    FileLogger f(LogLevels::DEBUG, "log.txt");
    testLogger(f);
}
*/

/*
void testLogger(Logger* l)
{
    l->Log("abc", LogLevels::ERROR);
    l->Log("def", LogLevels::INFO);
    l->Log("ghi", LogLevels::WARNING);
}

int main()
{
    Logger* c = new ConsoleLogger(LogLevels::WARNING);
    testLogger(c);

    Logger* f = new FileLogger(LogLevels::DEBUG, "log.txt");
    testLogger(f);
}
*/

void testLogger(Logger& logger) // 참조를 넘겨주는 식
{
    logger.Log("abc", LogLevels::ERROR); // doLogJob() 메서드는 가상 함수이기 때문에, 동적 바인딩이 일어남
    logger.Log("def", LogLevels::INFO);
    logger.Log("ghi", LogLevels::WARNING);
}

int main()
{
    ConsoleLogger c(LogLevels::WARNING);
    testLogger(c);

    FileLogger f(LogLevels::DEBUG, "log.txt");
    testLogger(f);
}

// 5번 문제가 있기는 한데, 설명할 내용이 많아서 생략

// 상속 단원 마무리
// -> 부록 : 객체 지향 프로그래밍 자체의 본질적인 문제점에 대해 알아볼 것임
