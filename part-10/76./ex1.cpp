// 지난 시간에는 상속에 대해서 알아봤음
// 이번 시간에는 상속이 필요한 이유에 대해서 알아볼 것임 (객체 지향 프로그래밍에서 상속을 사용해야 하는 이유)

// 메신저 앱 : 텍스트, 이미지, 음성, 동영상 등을 보낼 수 있음
// -> 이번 시간에는 텍스트와 이미지를 주고 받는 메신저를 간단하게 구현해볼 것임
// -> 텍스트 메시지, 이미지 메시지를 저장하는 클래스를 구현해볼 것임

#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    operator string() // string 으로 형 변환을 해주는 연산자를 오버로드
                      // -> 지금 당장은 이미지를 출력할 방법이 없음
                      // -> 이미지 정보를 string 으로 변환해서 출력
    {
        return "사진";
    }
};

/*
class TextMessage {
public:
    TextMessage(int sendTime, string sendName, string text)
    {
        this->sendTime = sendTime;
        this->sendName = sendName;
        this->text = text;
    }

    int GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }
    string GetText() const { return text; }

private:
    int sendTime;    // 보낸 시간은 편의상 int 형으로 표현 (C 언어에서는 실제로 시간을 int 에 저장)
    string sendName; // 보낸 사람 이름 (실제 메신저 앱에서는 사용자를 저장하는 클래스를 따로 둠)
    string text;     // 보낸 메시지 내용(텍스트)
};

class ImageMessage { // TextMessage 클래스와 거의 같은 형태
public:
    ImageMessage(int sendTime, string sendName, Image* image)
    {
        this->sendTime = sendTime;
        this->sendName = sendName;
        this->image = image;
    }

    int GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }
    Image* GetImage() const { return image; }

private:
    int sendTime;
    string sendName;
    Image* image; // 이미지 클래스가 있다고 가정 (구현은 생략)
                  // -> 객체 자체를 저장하지 않고, 객체에 대한 포인터를 저장할 것임
                  // -> 이미지 객체를 직접 저장하면 ImageMessage 객체의 크기가 엄청 커질 것임
};
*/

// TextMessage, ImageMessage 클래스는 똑같은 멤버를 가지고 있음 (sendTime, sendName)
// -> Message 라는 클래스를 새로 만들어서, 이러한 공통 멤버들을 한 번에 관리할 수 있음
// -> TextMessage, ImageMessage 가 Message 를 상속받게 하면, 공통 멤버들을 제거해도 됨
// -> 중복된 코드가 줄어들면서 코드가 좀 더 깔끔해질 것임

// 이것이 객체 지향 방식으로 프로그래밍을 하는 이유임
// -> 특히, 서로 비슷하면서 조금씩 다른 클래스가 여럿 있을 때에 아주 유용함
// -> 공통 멤버는 공통 멤버에서 따로 관리하고, 각 클래스가 자신의 고유한 멤버만 관리하도록 만들 수 있음

// 물론, 코드 구성이나 설계에 대해서는 정답이 따로 없음
// 효율적인 프로그램을 설계하는 방법에 대한 감을 익히는 것이 중요함

class Message {
public:
    // 자식 클래스에서는 부모의 private 멤버에 직접적으로 접근할 수 없음
    // -> 멤버들의 공개 수준을 protected 로 바꿔줘도 되긴 함
    // -> 하지만, 이러한 멤버들은 부모 클래스에서만 관리하는 것이 더 나음
    // -> 부모 클래스의 생성자에서 private 멤버들을 초기화하면 됨
    Message(int sendTime, string sendName)
    {
        this->sendTime = sendTime;
        this->sendName = sendName;
    }

    int GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }

private:
    int sendTime;
    string sendName;
};

class TextMessage : public Message {
public:
    /*
    TextMessage(int sendTime, string sendName, string text)
    {
        this->sendTime = sendTime;
        this->sendName = sendName;
        this->text = text;
    // 부모의 private 멤버에는 접근할 수 없어서 오류가 뜸
    // -> 부모 클래스의 생성자에서 초기화해줘야 함
    }
    */

    // 부모 클래스에서 멤버 초기화 생성자만 선언하면, 기본 생성자가 없다는 오류가 뜸
    // -> 컴파일러는, 클래스 생성자가 호출될 때, 자동으로 부모 클래스의 생성자를 호출함
    // -> 부모 클래스에 생성자가 여러 개 있으면, 그중 어떤 생성자를 호출해야 할지가 모호해짐
    // -> 부모 클래스에서 선언한 생성자를 사용하도록 직접 지정해줘야함
    // -> 생성자 위임으로 해결 가능
    TextMessage(int sendTime, string sendName, string text)
        : Message(sendTime, sendName)
    {
        this->text = text;
    }

    string GetText() const { return text; }

private:
    string text;
};

class ImageMessage : public Message {
public:
    ImageMessage(int sendTime, string sendName, Image* image)
        : Message(sendTime, sendName)
    {
        this->image = image;
    }

    Image* GetImage() const { return image; }

private:
    Image* image;
};

int main()
{
    // 두들 : "안녕"
    // 두들 : "강아지 사진"

    Image* p_dogImage = new Image(); // 생성자가 따로 없으니, 기본 생성자 사용
    TextMessage* hello = new TextMessage(10, "두들", "안녕");
    ImageMessage* dog = new ImageMessage(20, "두들", p_dogImage);

    cout << "보낸 시간 : " << hello->GetSendTime() << endl;
    cout << "보낸 사람 : " << hello->GetSendName() << endl;
    cout << "  내 용   : " << hello->GetText() << endl;
    cout << endl;

    cout << "보낸 시간 : " << dog->GetSendTime() << endl;
    cout << "보낸 사람 : " << dog->GetSendName() << endl;
    cout << "  내 용   : " << (string)*dog->GetImage() << endl; // *dog->GetImage() == 이미지 객체 -> string 으로 형 변환
    cout << endl;

    delete hello;
    delete dog;
    delete p_dogImage;
}

// main 함수 등, 다른 코드들을 전혀 건들지 않고도, 이렇게 코드 구성을 체계적으로 바꿀 수 있음

// 이 예제에서 알 수 있는 상속이 필요한 이유
// : 공통 멤버에 변화가 있을 때, 일일히 바꿔줄 필요가 없어진다.

// 진짜 중요한 이유는, 다다음 시간에 알아볼 예정 (다음 시간에는 가상 함수에 대해서 알아볼 것임)
