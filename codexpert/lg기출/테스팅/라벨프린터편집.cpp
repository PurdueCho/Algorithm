#include <cstdio>
#include <cstring>
#include <locale>
#include <vector>
#include "./lib/LabelPrinter.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다.
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 입력과 테스트 코드를 작성하시오.
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

/**
 * Input class
 * 입력된 키 내용을 가져올 수 있는 장치 인터페이스
 *
class Input
{
public:
	/**
	 * 입력된 키 내용을 가져올 수 있는 장치 인터페이스
	 * @return 입력된 키 값을 호출 할 때 마다 하나 씩 반환
	 *
	virtual char getKeyInput() = 0;
};
*/

/**
 * LCD에 커서와 문자를 표시하는 인터페이스
 *
 * @param buffer 출력할 문자가 있는 버퍼 위치. 지정한 주소부터 15자를 읽어서 LCD에 표시한다. (버퍼의 유효성 보장 필요)
 * @param cursurPosition 커서를 표시할 위치. 0인 경우 가장 왼쪽, 15인 경우 가장 오른쪽 경계에 커서를 표시한다. -1인 경우에는 LCD에 커서를 표시하지 않는다. 
 
void writeLcd(char* buffer, int cursurPosition);
*/

/**
 * LabelPrinter class
 * 라벨 프린터를 제어 (테스트 대상)
 *
class LabelPrinter
{
public:
	/**
	 * 라벨 프린터를 제어하는 모듈을 초기화
	 * 최초 LCD나 입력 상태 등을 초기화하는 로직이 포함되어 있다.
	 *
	LabelPrinter(Input& inputDevice) : input_(inputDevice) {}

	/**
	 * 테스트 대상인 라벨 프린터 편집기의 입력을 처리하고 결과를 LCD에 출력한다.
	 *
	void processInput()
	{
		char key = input_.getKeyInput();

		switch (key)
		{
		case KEY_LEFT:
			--cursorPos_;
			break;
		case KEY_RIGHT:
			if (!isalpha(displayBuffer_[cursorPos_]))
				break;
			++cursorPos_;
			break;
		case KEY_BACKSPACE:
			for (int i = cursorPos_; i <= strlen(displayBuffer_); ++i)
				displayBuffer_[i-1] = displayBuffer_[i];
			--cursorPos_;
			break;
		default:
			for (int i = strlen(displayBuffer_); i >= cursorPos_; --i)
				displayBuffer_[i+1] = displayBuffer_[i];
			displayBuffer_[cursorPos_] = key;
			++cursorPos_;
			break;
		}

		writeLcd(displayBuffer_, cursorPos_);
	}

private:
	Input& input_;
	char displayBuffer_[16] = { 0, };
	int cursorPos_ = 0;
};
*/

/*
입력 키를 정의할 때 사용할 상수.

#define KEY_LEFT    '1'
#define KEY_RIGHT   '2'
#deifne KEY_DELETE  '3'
*/

/* [문제 1. 작성 내용] */
// 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 형식: { 입력 갯수, 입력 키1, 입력 키2, ... , 입력 키 N }

// 샘플 Testcase : 문제의 '[ 키 입력 동작의 예 ]' 를 테스트 하기 위한 예제
// 라벨 프린터에 입력할 키 값을 의미 (첫번째 요소는 라벨 프린터에 입력할 키 값의 개수)
char sampleInput_keys[MAX_KEY_LIMIT + 1] = {10, 'A', 'B', KEY_LEFT, 'X', KEY_RIGHT, KEY_BACKSPACE, KEY_RIGHT, KEY_LEFT, KEY_LEFT, KEY_BACKSPACE};

//TODO: (문제1-1) - 최종 결과물 : ABCDEF
char test_1_1_keys[MAX_KEY_LIMIT + 1] = {
    11, KEY_RIGHT, 'A', 'B', 'C', 'D', 'E', 'F', 'G', KEY_BACKSPACE, KEY_LEFT, KEY_RIGHT};

//TODO: (문제1-2) - 초기 상태 : ABCD, 커서 위치 : B와 C 사이, 최종 결과물 : PABDOEL
char test_1_2_keys[MAX_KEY_LIMIT + 1] = {
    12, KEY_LEFT, KEY_LEFT, 'P', KEY_RIGHT, KEY_RIGHT, KEY_RIGHT,
    KEY_BACKSPACE, KEY_RIGHT, KEY_RIGHT, 'O', 'E', 'L'};

//TODO: (문제1-3) - 초기 상태 : POWER, 커서 위치 : W와 E 사이, 최종 결과물 : OOEOL , 최종 커서 위치 : 세번째 문자 'E'와 네번쨰 문자'O' 사이
char test_1_3_keys[MAX_KEY_LIMIT + 1] = {
    13, KEY_BACKSPACE, KEY_LEFT, KEY_BACKSPACE, 'O', KEY_RIGHT, KEY_RIGHT, KEY_RIGHT, KEY_RIGHT,
    KEY_BACKSPACE, 'O', 'L', KEY_LEFT, KEY_LEFT};

/* [문제 2. 작성 내용] */
// NOTE: 답안 코드 실행 중 메모리 누수가 발생하면 오답 처리됨

namespace
{
    struct FakeInput : public Input
    {
        FakeInput(char *fakeKeys) : fakeKeys_(fakeKeys) {}

        char getKeyInput()
        {
            return fakeKeys_[count_++];
        }

    private:
        char *fakeKeys_;
        int count_ = 0;
    };
} // namespace

void test_2_1(void)
{
    // TODO: (문제2-1)
    // 키 입력이 다음의 순서대로 발생하는 상황 - ('A' 영문자 키) -(왼쪽 커서 이동키) -('P' 영문자 키) -(삭제 키)
    char keys[] = {'A', KEY_LEFT, 'P', KEY_BACKSPACE};

    FakeInput input(keys);
    LabelPrinter printer(input);

    for (int i = 0; i < sizeof(keys); i++)
    {
        printer.processInput();
    }
}

void test_2_2(void)
{
    // TODO: (문제2-2)
    // 키 입력이 다음의 순서대로 발생하는 상황 - ('L' 영문자 키) -('O' 영문자 키) - (왼쪽 커서 이동키) -(삭제 키) -(오른쪽 커서 이동키) -('X'영문자 키)
    char keys[] = {'L', 'O', KEY_LEFT, KEY_BACKSPACE, KEY_RIGHT, 'X'};

    FakeInput input(keys);
    LabelPrinter printer(input);

    for (int i = 0; i < sizeof(keys); i++)
    {
        printer.processInput();
    }
}

// (문제2-3) 다음과 같이 정의된 TestCase를 입력 받아서
// 해당 input으로 키 입력이 발생하는 상황을 재현하고, 키 입력이 끝난 후 LCD에 표시되는 결과를 expected와 비교하여 검증하는 코드를 구현하라.
// 단, expected와 같은지 확인하는 verify API는 반드시 아래의 API를 이용하도록 한다.

//void assertEquals(const char* expected, const char* actual);

/**
 * LCD에 커서와 문자를 표시하는 인터페이스 writeLcd에 해당하는 dummy
 */

const char *lastBuffer = "";

void writeLcd(const char *buffer, int cursurPosition)
{
    // TODO: (문제2-3) 필요한 test-double spy로 간접적으로 LabelPrinter의 결과를 추출할 수 있음
    lastBuffer = buffer;
}

using KeySequence = std::vector<char>;
/**
 * @param {KeySequence} inputKeys: processInput()에 입력될 키값들
 * @param {string} expected: 입력(inputKeys)에 대한, processInput()의 수행 결과 문자열
 */
void test_2_new(const KeySequence &inputKeys, const std::string &expected)
{
    // TODO: (문제2-3)
    // 주어진 Input(inputKeys)값으로 LabelPrinter를 동작시키고, 그 결과를 주어진 예상 결과값(expected)과 검증하는 테스트 코드를 작성하라.

    class FakeInput : public Input
    {
    public:
        FakeInput(decltype(inputKeys) sequence)
        {
            k = sequence.begin();
        }

        char getKeyInput()
        {
            return *k++;
        }

    private:
        KeySequence::const_iterator k;
    };

    FakeInput input(inputKeys);
    LabelPrinter printer(input);

    for (auto key : inputKeys)
    {
        printer.processInput();
    }

    // 최종 결과값 검증은 다음 함수(assertEquals)를 통해 수행 할 수 있다.
    // assertEquals(expected, actualResult);
    assertEquals(expected.c_str(), lastBuffer);

    lastBuffer = "";
}

/* [문제 3. 작성 내용] */
// 기능 요구사항 대로 처리할 수 없는 모든 예외 상황을 표현하는 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
/* 테스트 케이스의 형식:
{
	테스트 케이스 수,
	{
		{ 입력 갯수, 입력 키1, 입력 키2, ..., 입력 키 N },
		...
		{ 입력 갯수, 입력 키1, 입력 키2, ..., 입력 키 N }
	}
};
*/

typedef char InputSequence[MAX_KEY_LIMIT];

struct ExceptionalCases
{
    int numberOfCases;
    InputSequence inputKeys[10];
};

// TODO: (문제3)
ExceptionalCases test_3_cases = {
    3, /* FIXME */
    {
        {1, KEY_BACKSPACE},
        {1, KEY_LEFT},
        {16, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'p'}}};

/* [문제 4. 작성 내용] */
/**
 * LCD 한 줄에 커서와 문자를 표시하는 인터페이스
 *
 * @line 출력할 줄 위치. 0이면 가장 윗줄, 1이면 두번째 줄에 출력한다.
 * @param buffer 출력할 문자가 있는 버퍼 위치. 지정한 주소부터 15자를 읽어서 line에 해당하는 줄에 표시한다. (버퍼의 유효성 보장 필요).
				 a-z, A-Z 문자 값을 출력하며 0은 빈칸으로 출력한다.
 * @param cursurPosition 커서를 표시할 위치. 0인 경우 line에 해당하는 줄의 가장 왼쪽, 15인 경우 line에 해당하는 줄의 가장 오른쪽 경계에 커서를 표시한다. -1인 경우에는 line에 해당하는 줄에는 커서를 표시하지 않는다.

void writeLine(int line, char* buffer, int cursurPosition);

사용 예
	writeLine(0, ..., 0); // 첫번째 줄 가장 왼쪽에 커서를 표시
	writeLine(1, ..., 15); // 두번째 줄 가장 오른쪽에 커서를 표시

	writeLine(0, ..., -1); writeLine(1, ..., 0); 첫번째 줄에는 커서를 표시하지 않고 두번째 줄 가장 왼쪽에 커서를 표시	
*/

// TODO: (문제4) 요구사항을 만족하도록 아래 클래스의 코드를 수정하시오.
class LabelPrinterExt
{
public:
    /**
	 * 라벨 프린터를 제어하는 모듈을 초기화
	 * 최초 LCD나 입력 상태 등을 초기화하는 로직이 포함되어 있다.
	 */
    LabelPrinterExt(Input &inputDevice) : input_(inputDevice) {}

    /**
	 * 테스트 대상인 라벨 프린터 편집기의 입력을 처리하고 결과를 LCD에 출력한다.
	 * 키가 하나 입력될 때 마다 호출된다.
	 */
    void processInput()
    {
        char key = input_.getKeyInput();

        switch (key)
        {
        case KEY_LEFT:
            --cursorPos_;
            break;
        case KEY_RIGHT:
            if (!isalpha(displayBuffer_[cursorPos_]))
                break;
            ++cursorPos_;
            break;
        case KEY_BACKSPACE:
            for (int i = cursorPos_; i <= strlen(displayBuffer_); ++i)
                displayBuffer_[i - 1] = displayBuffer_[i];
            --cursorPos_;
            break;
        default:
            for (int i = strlen(displayBuffer_); i >= cursorPos_; --i)
                displayBuffer_[i + 1] = displayBuffer_[i];
            displayBuffer_[cursorPos_] = key;
            ++cursorPos_;
            break;
        }

        // TODO: 아래와 같이 writeLine를 호출해서 LCD로 출력한다.
        // writeLine(0, displayBuffer_, cursorPos_); // 윗줄 출력
        // writeLine(1, ...); // 아랫줄 출력
        writeLine(0, displayBuffer_, cursorPos_ < 15 ? cursorPos_ : -1);
        writeLine(1, displayBuffer_+15, cursorPos_ < 15 ? -1 : cursorPos_ - 15);
    }

private:
    Input &input_;
    char displayBuffer_[100] = {
        0,
    };
    int cursorPos_ = 0;
};

// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점과 관련이 없다.
int main()
{
    printTestInputResult("Sample Input", "", 0, sampleInput_keys);

    printTestInputResult("Test_1_1 Input", "", 0, test_1_1_keys);
    printTestInputResult("Test_1_2 Input", "ABCD", 2, test_1_2_keys);
    printTestInputResult("Test_1_3 Input", "POWER", 3, test_1_3_keys);

    test_2_1();
    test_2_2();

    return 0;
}