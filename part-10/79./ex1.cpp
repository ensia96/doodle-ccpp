#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    operator string()
    {
        return "사진";
    }
};

class Message {
public:
    Message(int sendTime, string sendName)
        : sendTime(sendTime)
        , sendName(sendName)
    {
    }

    int GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }

    virtual string GetContent() const
    {
        return ""; // Message 클래스에는 반환하기에 적합한 자료가 없음
                   // -> 빈 문자열을 반환하도록 구현
    }
    // Message 객체 자체에서 GetContent 메서드를 호출할 수도 있음
    // -> GetContent 메서드를 만든 목적에 위배됨
    // -> 이를 예방하는 방법은 다음 시간에 알아볼 것임

private:
    int sendTime;
    string sendName;
};

class TextMessage : public Message {
public:
    TextMessage(int sendTime, string sendName, string text)
        : Message(sendTime, sendName)
        , text(text)
    {
    }

    string GetText() const { return text; }
    string GetContent() const { return text; } // GetContent 메서드 오버라이딩

private:
    string text;
};

class ImageMessage : public Message {
public:
    ImageMessage(int sendTime, string sendName, Image* image)
        : Message(sendTime, sendName)
        , p_image(image)
    {
    }

    Image* GetImage() const { return p_image; }
    string GetContent() const { return (string)*p_image; } // GetContent 메서드 오버라이딩

private:
    Image* p_image;
};

/*
void printMessage(TextMessage* m) // 인자로 참조 값을 받아도 되지만, 우선은 포인터로 선언
{
    cout << "보낸 시간 : " << m->GetSendTime() << endl;
    cout << "보낸 사람 : " << m->GetSendName() << endl;
    cout << "  내 용   : " << m->GetText() << endl;
    cout << endl;
}

void printMessage(ImageMessage* m)
{
    cout << "보낸 시간 : " << m->GetSendTime() << endl;
    cout << "보낸 사람 : " << m->GetSendName() << endl;
    cout << "  내 용   : " << (string)*m->GetImage() << endl;
    cout << endl;
}

// 이렇게 출력용 함수를 만들면, 출력할 메시지가 늘어도 편하게 처리할 수 있음
// -> 오버라이딩을 활용하면, 더 효율적으로 처리할 수 있음

// 목표
// - 비슷한 역할을 하는 함수들을 엮는 식으로 클래스 구조 개선하기 (GetText, GetImage)
// - 출력용 함수들 하나로 합치기 (printMessage(ImageMessage*), printMessage(TextMessage*))
// - 출력용 함수가 부모 클래스 포인터를 인자로 받도록 개선하기 (-> printMessage(Message*))
//    -> 인자로 들어온 객체의 자료형에 따라 다르게 동작하도록 구현

// 호출 대상에 따라 실행되어야 하는 get 함수가 다름
// -> 이런 상황에서, 동적 바인딩을 활용할 수 있음
// -> Message 클래스에 가상 함수 추가 + 파생 클래스에서 메서드 오버라이딩
*/

/*
void printMessage(Message* m)
{
    cout << "보낸 시간 : " << m->GetSendTime() << endl;
    cout << "보낸 사람 : " << m->GetSendName() << endl;
    cout << "  내 용   : " << m->GetContent() << endl;
    cout << endl;
}

// printMessage(hello) 의 경우,
// -> printMessage 함수의 인자로 TextMessage* hello 가 들어감 (Message* m = hello)
// -> m->GetContent() 코드가 실행되면, TextMessage::GetContent 가 호출되어 TextMessage::text 가 반환될 것임
// -> Message::GetContent 는 가상 함수로 선언되어 있고, TextMessage::GetContent 로 오버라이딩되어 있기 때문

// printMessage(dog) 의 경우,
// -> printMessage 함수의 인자로 ImageMessage* dog 이 들어감 (Message* m = dog)
// -> m->GetContent() 코드가 실행되면, ImageMessage::GetContent 가 호출되어 (string)*ImageMessage::p_image 가 반환될 것임
// -> Message::GetContent 는 가상 함수로 선언되어 있고, ImageMessage::GetContent 로 오버라이딩되어 있기 때문

// 이렇게, 부모 클래스 포인터를 매개 변수로 두면, 동적 바인딩을 통해 자식마다 다르게 처리해줄 수 있음
// -> 함수 하나로 모든 자식 클래스에 대해, 올바른 동작을 수행할 수 있게 됨
// -> 이렇게, 구현할 함수도 줄어들고, 클래스 구조도 깔끔해진다는 것이 상속을 통해 얻을 수 있는 이점임
*/

/*
// 지금까지는 기반 클래스 포인터를 통해 일어나는 동적 바인딩에 대해서만 살펴봤음
// -> 물론, 동적 바인딩이 '포인터를 통해 멤버를 호출하는 상황' 에 대해서만 일어나는 것은 아님
// -> 아래처럼 참조 변수를 통해 멤버를 호출할 때도 동적 바인딩이 일어남
void printMessage(const Message& m) // 참조 변수이므로, 상수화해줘야 함
{
    cout << "보낸 시간 : " << m.GetSendTime() << endl;
    cout << "보낸 사람 : " << m.GetSendName() << endl;
    cout << "  내 용   : " << m.GetContent() << endl;
    cout << endl;
    // 포인터를 사용했을 때보다는 코드가 조금 더 깔끔해짐
}
*/

// 객체 자체가 아닌 포인터와 참조를 넘겨주기 때문에 동적 바인딩이 일어나는 것임
// -> 아래처럼 객체를 직접 인자로 받으면, 기존에 의도했던 데로 출력되지 않음
// -> 참조 형식으로 인자를 넘겨주지 않고, 객체 자체가 매개 변수에 들어가게 되기 때문
// -> 매개 변수 m에 객체가 복사됨 (Message m = <Message 객체>;)
// -> Message.GetContent() 부분에서 Message::GetContent 메서드가 호출됨
void printMessage(const Message m)
{
    cout << "보낸 시간 : " << m.GetSendTime() << endl;
    cout << "보낸 사람 : " << m.GetSendName() << endl;
    cout << "  내 용   : " << m.GetContent() << endl;
    cout << endl;
}

int main()
{
    Image* p_dogImage = new Image();
    /*
    TextMessage* hello = new TextMessage(10, "두들", "안녕");
    ImageMessage* dog = new ImageMessage(20, "두들", p_dogImage);

    cout << "보낸 시간 : " << m->GetSendTime() << endl;
    cout << "보낸 사람 : " << m->GetSendName() << endl;
    cout << "  내 용   : " << m->GetText() << endl;
    cout << endl;

    cout << "보낸 시간 : " << dog->GetSendTime() << endl;
    cout << "보낸 사람 : " << dog->GetSendName() << endl;
    cout << "  내 용   : " << (string)*dog->GetImage() << endl;
    cout << endl;

    // 출력 부분이 중복됨
    // -> 함수로 묶어서 한 번에 처리하면 더 좋을 것임
    // -> 그런데, 객체마다 호출해야 하는 함수가 다름 (출력할 내용이 서로 다르기 때문)
    // -> 객체를 인자로 받는 출력용 함수를 만들어 오버로딩하는 방법이 있음
    */

    /*
    TextMessage* hello = new TextMessage(10, "두들", "안녕");
    ImageMessage* dog = new ImageMessage(20, "두들", p_dogImage);

    // printMessage(Message*)
    printMessage(hello);
    printMessage(dog);

    // printMessage(Message&)
    printMessage(*hello);
    printMessage(*dog);
    */

    // 메신저 프로그램에서 메시지를 한두개만 보내는 상황은 거의 없을 것임
    // -> 메시지를 저장하는 가장 합리적인 방법은, 메시지를 배열에 저장하는 방법일 것임
    // -> 그냥 Message 객체를 저장하는 배열을 만들면, 파생 클래스의 객체들을 저장할 수 없음
    // -> Message 객체의 크기를 기준으로 메모리 공간이 할당될 것이기 때문 (파생 클래스의 객체가 저장되기엔 부족)
    // -> 파생 클래스까지 저장하고 싶다면, Message* 를 저장하는 배열을 사용해야 함
    Message* messages[] = {
        new TextMessage(10, "두들", "안녕"),
        new TextMessage(11, "두들", "안녕"),
        new TextMessage(12, "두들", "안녕"),
        new ImageMessage(20, "두들", p_dogImage)
    };

    for (Message* m : messages) {
        printMessage(*m);
    }

    /*
    for (int i = 0; i < 4; i++) {
        printMessage(*messages[i]);
    }
    */

    delete p_dogImage;
    for (Message* m : messages) {
        delete m;
    }
}

// 이번 시간에는, 이렇게, 동적 바인딩을 활용함으로써 생기는 상속의 이점에 대해서 살펴봤음
// 다음 시간에는, 위에서 잠시 언급했었던 가상 함수 관련 문제에 대해서 살펴볼 것임
