#include <stdio.h>

#include "lib/AllocMemory.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다.
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 케이스 입력과 테스트 코드를 작성하시오.
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

/**
 * 상수 정의
 *
#define MAX_REQ_LIMIT	(50)
#define MEMORY_SIZE		(20)
*/

/**
 * CommInterface struct
 * 입력된 요청을 가져오고 결과를 전송할 수 있는 인터페이스에 대한 함수 포인터로 구성된다.
 *
 *

typedef struct CommInterface_
{
	/**
	 * 호출할 떄 마다 메시지 큐에 있는 요청을 하나 꺼내서 요청 값을 받아온다.
	 * @return 받은 요청 값
	 *
	int (*getReqInput)();
	
	/**
	 * 처리 결과를 전송한다.
	 * @param result 전송할 값
	 *
	void (*send)(int result);
} CommInterface;

*/

/*
 * [테스트 대상] 메모리 할당 모듈
 *

 /**
 * 메모리를 할당하고 반납하는 모듈을 초기화
 * 메모리 상태 등을 초기화하는 로직이 포함되어 있음
 *
 * @param io 할당/해제 요청을 받고 결과를 전송하는 통신 인터페이스
 *
void Allocator_init(CommInterface* comm)
{
	io_ = *comm;

	resetStatus();
}


/**
 * 메모리 할당 및 반납 (테스트 대상)
 *
void Allocator_processRequest()
{
	BOOL isAlloc = TRUE;
	int result = 0;
	int alloc, id, size;
	int req = io_.getReqInput();

	if (req < 0) {
		req = -req;
		isAlloc = FALSE;
	}
	id = req / 10;
	size = req % 10;

	if (isAlloc)
		result =  allocate(id, size);
	else
		result = dellocate(id, size);

	io_.send(result);
}


/**
 * 크기 만큼 연속적으로 남아있는 메모리를 할당한다.
 * @param id 할당할 메모리 id
 * @param size 할당할 크기
 * @return 할당에 성공하는 경우 시작하는 위치, 실패할 경우 -1
 *
static int allocate(int id, int size)
{
	// 빈 공간 검사
	int firstFitPosition = -1;
	for (int i = 0; i < MEMORY_SIZE; i++) {
		int j = 0;
		if (memoryStatus_[i] == 0) {
			int count = 0;
			for (j = i; j < MEMORY_SIZE; j++) {
				if (memoryStatus_[j] == 0) count++;
				else {
					break;
				}
			}
			if (count >= size) {
				firstFitPosition = i;
				break;
			}
			i = j;
		}
	}
	if (firstFitPosition < 0) {
		return -1;
	}
	// 메모리 할당
	for (int i = firstFitPosition; i < firstFitPosition + size; i++) {
		memoryStatus_[i] = id;
	}
	freeSpace_ -= size;

	return firstFitPosition;
}

/**
 * 할당한 메모리를 찾아서 반환할 크기만큼 해제한다.
 * @param id 할당한 메모리 id
 * @param size 반환할 크기
 *
static int dellocate(int id, int size)
{
	int found = -1;
	// 기존 아이디 검색
	for (int i = 0; i < MEMORY_SIZE; i++) {
		if (memoryStatus_[i] == id) {
			int count = 0;
			found = 1;

			for (int j = i; j < MEMORY_SIZE; j++) {
				if (memoryStatus_[j] == id) count++;
				else {
					break;
				}
			}

			for (int j = i; j < i + size; j++) {
				memoryStatus_[j] = 0;
			}
			freeSpace_ += size;

			return 0;

		}
	}
	if (found == -1) {
		return -1;
	}

	return 0;
}
*/

/* [문제 1. 작성 내용] */
// 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 형식: { 입력 갯수, 입력 요청 값 1, 입력 요청 값 2, ... , 입력 요청 값 N }

// 테스트 케이스 예) 입력 요청값이 14, 38, -14, 22, 43, 16 순으로 오는 경우
int sampleInput_keys[MAX_REQ_LIMIT + 1] = {6, 14, 38, -14, 22, 43, 16};

int test_1_1_keys[MAX_REQ_LIMIT + 1] = {
    13, 11, 22, 34, 48, 58, 65, -48, 47, -11, -22, -34, -47, 15,
}; //TODO: 문제1.(1-1) - 최종 남은 용량이 10KB가 되는 상황
int test_1_2_keys[MAX_REQ_LIMIT + 1] = {
    15, 11, 22, 34, 48, 58, 65, -48, 47, -11, -22, -34, 12, 22, -12, 14,
}; //TODO: 문제1.(1-2) - 최종 남은 용량이 6KB이지만 연속으로 4KB인 공간이 없는 상황

// [문제2. 작성 내용]
// 원하는 요청 값을 전달할 수 있도록 fake/stub을 구현하여 제시된 상황을 재현하는 테스트 코드를 작성하시오.
// NOTE: 답안 코드 실행 중 메모리 누수가 발생하면 오답 처리됨

static const int* fakeInput;
static int count;
static int lastResult;

void Mock_setRequestSequence(const int fakeInputSequence[]) {
	fakeInput = fakeInputSequence;
	count = 0;
	lastResult = -100;
}

int Mock_getLastResult() {
	return lastResult;
}

static int getReqInput_fake() {
	return fakeInput[count++];
}

static void send_spy(int result) {
	lastResult = result;
}

void Mock_init(CommInterface* io) {
	io->getReqInput = getReqInput_fake;
	io->send = send_spy;
}

void test_2_1(void)
{
    // TODO: // 문제2.(2-1)
    // 요청 값의 입력이 다음의 순서대로 발생하는 상황: 12 -> 24 -> 38 -> -38 -> -12
	int inputs[] = { 12, 24, 38, -38, -12};

	CommInterface io;
	Mock_init(&io);
	Mock_setRequestSequence(inputs);

	Allocator_init(&io);

	for (int i = 0 ; i < 5 ; i++) {
		Allocator_processRequest();
	}
}

void test_2_2(void)
{
    // TODO: 문제2.(2-2)
    // 요청 값의 입력이 다음의 순서대로 발생하는 상황: 18 -> 21 -> -18 -> 33 -> 41 -> -33
	int inputs[] = {18, 21, -18, 33, 41, -33};
	
	CommInterface io;
	Mock_init(&io);
	Mock_setRequestSequence(inputs);

	Allocator_init(&io);

	for (int i = 0; i < 6; i++)
	{
		Allocator_processRequest();
	}
}

// 다음과 같이 정의된 TestCase를 입력 받아서
// 해당 input으로 요청값이 발생하는 상황을 재현하고, 마지막으로 전송되는 결과를  expected와 비교하여 검증하는 코드를 구현하라.
// 단, expected와 같은지 확인하는 verify API는 반드시 아래의 API를 이용하도록 한다.

//void assertEquals(int expected, int actual);

void test_2_3(const int inputReqs[], int numOfInput, int expected)
{
    // TODO: 문제 2-3

	CommInterface io;
	Mock_init(&io);
	Mock_setRequestSequence(inputReqs);

	Allocator_init(&io);

	for (int i = 0; i < numOfInput; i++)
	{
		Allocator_processRequest();
	}

	assertEquals(expected, Mock_getLastResult());

	//assertEquals(expected, send를 통해 전달되는 값 중 마지막 값);
}

/* [문제 3. 작성 내용] */
// 기능 요구사항 대로 처리할 수 없는 모든 예외 상황을 식별해서 해당 상황을 표현하는 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 제시된 형식에 맞지 않는 입력은 없다고 가정하고,
// 예외의 종류마다 1개씩 구분하여 추가한다.

/* 테스트 케이스의 형식:
{
	테스트 케이스 수,
	{
		{ 입력 갯수, 입력 요청 값 1, 입력 요청 값 2, ..., 입력 요청 값 N },
		...
		{ 입력 갯수, 입력 요청 값 1, 입력 요청 값 2, ..., 입력 요청 값 N },
	}
};
*/

typedef int InputSequence[MAX_REQ_LIMIT];

struct ExceptionalCases
{
    int numberOfCases;
    InputSequence inputKeys[10];
};

// TODO: 문제 3
struct ExceptionalCases test_3_cases = {

	3, /* FIXME */
	{
		{14, 11, 22, 34, 48, 58, 65, -48, 47, -11, -22, -34, -47, 15, 11},	// ERR_DUPLICATED_ID
		{14, 11, 22, 34, 48, 58, 65, -48, 47, -11, -22, -34, -47, 15, -71},	// ERR_NO_ID_FOUND
		{ 2, 13, -14 }, // ERR_invalid_SIZE

	}};

// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점과 관련이 없다.
int main()
{
    printTestInputResult("Sample Input", sampleInput_keys);
    printTestInputResult("Test_1_1 Input", test_1_1_keys);
    printTestInputResult("Test_1_2 Input", test_1_2_keys);

    test_2_1();
    test_2_2();

    return 0;
}