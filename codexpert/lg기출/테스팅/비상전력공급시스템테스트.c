#include <stdio.h>
#include <string.h>

// 필요한 표준헤더는 여기에 추가할 수 있다.

#include "./lib/managePower.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다.
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 입력과 테스트 코드를 작성하시오.
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

/**
 * 상수정의
 *
#define	MAX_INPUT_LIMIT	(20)
#define	MAP_SIZE		(9+1)

#define BOOL int
#define FALSE 0
#define TRUE (!FALSE)
 */

/**
  * RemoteController class
  * 입력된 위치의 장비를 가동시키는 장치 인터페이스
  *

 struct RemoteController
 {
	 /**
	  * 요청한 위치의 장비를 가동시키는 함수를 가리키는 포인터
	  * @param row 행 위치
	  * @param col 열 위치
	  *
	 void (*on)(int row, int col);
 };
 */

/**
  * [테스트 대상]
  * PowerManager 모듈
  * 전력 공급 장치를 배치/회수하고 전력 현황을 계산
  *

 static RemoteController controller_;   // 장비를 가동시키기 위한 인터페이스
 static int pwrNeeds_[MAP_SIZE][MAP_SIZE];  //[row][col] 위치의 전력 요구량
 static int pwrMap_[MAP_SIZE][MAP_SIZE];  // [row][col] 위치의 전력 공급량
 static BOOL pwrPos_[MAP_SIZE][MAP_SIZE];  // [row][col] 위치에 전력 공급 장치가 있다면 TRUE
 static int pwrCount_ = 0; // 현재 배치된 전력 공급 장치의 수


 /**
  * 전력공급장치를 제어하는 모듈 초기화
  * 최초의 전력 공급 장치, 장비 정보 등 필요한 내용을 초기화하는 로직이 포함되어 있다.
  * @param controller 장비를 켜는 인터페이스 함수 포인터가 있는 구조체
  *
 void PwrMgr_init(RemoteController controller) {
	 controller_ = controller;
	 //... 필요한 초기화 코드 생략
 }

 /**
  * 전력 공급 장치를 배치했을 때의 전력 현황을 계산하고 배치 후 가동 가능한 장비가 있으면 해당 장비를 가동시킨다.
  *
  * @param row 전력 공급 장치를 배치할 행 위치
  * @param col 전력 공급 장치를 배치할 열 위치
  * @return 배치가 가능한 경우 TRUE, 가능하지 않은 경우 FALSE
  *
 BOOL PwrMgr_putPowerSupply(int row, int col)
 {
	 if (pwrCount_ >= CNT_MAX) {						//	최대 배치 수에 도달했는지 체크
		 return FALSE;
	 }

	 if (checkPowerDistance(row, col)) {			//	거리 2 내에 다른 power 있는지 체크
		 return FALSE;
	 }

	 pwrPos_[row][col] = TRUE;
	 ++pwrCount_;

	 doSupplyPower(2, row, col);
	 return TRUE;
 }

 /**
  * 전력 공급 장치를 회수했을 때의 전력 현황 등 관련 정보를 계산한다.
  *
  * @param row 전력 공급 장치를 회수할 행 위치
  * @param col 전력 공급 장치를 회수할 열 위치
  * @return 회수가 가능한 경우 true, 가능하지 않은 경우 false
  *
 BOOL PwrMgr_removePowerSupply(int row, int col)
 {
	 pwrPos_[row][col] = FALSE;

	 doSupplyPower(-2, row, col);
	 return TRUE;
 }


 static BOOL checkPowerDistance(int row, int col) {
	 for (int i = row - 2; i <= row + 2; i++) {
		 if (i < 1 || i > 9)	continue;			//	MAP 범위 밖은 체크하지 않음
		 for (int j = col - 2; j <= col + 2; j++) {
			 if (j < 1 || j > 9)	continue;		//	MAP 범위 밖은 체크하지 않음
			 if ((abs(i - row) + abs(j - col)) > 2) continue;	//	거리가 3 이상이면 체크대상 아님

			 if (pwrPos_[i][j])
				 return TRUE;  // 거리 2 내에 다른 Power 존재
		 }
	 }
	 return FALSE;
 }

 static void turnOn(int row, int col)
 {
	 if (controller_.on)
		 controller_.on(row, col);
 }

 static void doSupplyPower(int supply, char row, char col)
 {
	 for (int i = row - 1; i <= row + 1; i++) {
		 if (i < 1) continue;  // MAP 범위 밖은 체크하지 않음

		 for (int j = col - 1; j <= col + 1; j++) {
			 if (j < 1) continue; //	MAP 범위 밖은 체크하지 않음

			 BOOL wasOffedDev = pwrNeeds_[i][j] > pwrMap_[i][j];
			 pwrMap_[i][j] += supply;

			 if (wasOffedDev && pwrNeeds_[i][j] <= pwrMap_[i][j])
				 turnOn(i, j);   // 공급량이 필요량보다 많아지게 되면 장비 가동
		 }
	 }
 }
 */

/* [문제 1. 작성 내용] */
// 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 형식: { {종류(PUT/REMOVE), 행,열}, ..., {종류(PUT/REMOVE), 행,열} }
/*
 struct Case {
	 int cmd;
	 int row;
	 int col;
 };
 
struct TestInput {
	int length;
	Case cases[MAX_INPUT_LIMIT];
};
*/

// 테스트 케이스 예: (7,7)와 (4,1)에 전력 공급 장치를 배치하고, (3,3)의 전력 공급 장치를 회수하는 경우
TestInput sampleInput_case = {3, {{PUT, 7, 7}, {PUT, 4, 1}, {REMOVE, 3, 3}}};

//TODO: 문제1.(1-1) - 실행 후 전원 공급이 되지 않은 장비 개수가 3개인 상황
TestInput test_1_1_case = {6, { {PUT,6,3}, {REMOVE,6,3}, {PUT,6,3}, {PUT,7,7}, {PUT,4,1}, {PUT,4,5} }};

//TODO: 문제1.(1-2) - 최종적으로 미 작동 장비가 없었다가 전력 공급 장치가 하나 회수되어 미작동 장비가 2개가 되는 상황
TestInput test_1_2_case = {9, { {REMOVE,3,3}, {PUT,2,3}, {PUT,3,7}, {PUT,4,1}, {PUT,4,4},
    {PUT,6,2}, {PUT,6,9}, {PUT,7,7}, {REMOVE,2,3} }};

//TODO: 문제1.(1-3) - 최종적으로 전력 공급 장치를 하나 추가하여 3개 이상의 미작동 장비가 한번에 작동하는 상황
TestInput test_1_3_case = {2, { {PUT,6,9}, {PUT,7,7} }};

// [문제2. 작성 내용]
// 원하는 요청 값을 전달할 수 있도록 test spy/stub/driver를 구현하여 제시된 상황을 재현하는 테스트 코드를 작성하시오.
// NOTE: 각 함수안에 해당 테스트 실행에 필요한 코드가 모두 포함되어야 한다.

void test_2_1(void)
{
    // TODO: (문제2-1)
    // 전력 공급 장치의 추가/회수가 다음의 순서대로 실행되는 상황
    // (1, 2)에 추가 -> (9, 9)에 추가 -> (3, 3)의 장치 회수 -> (2, 7)에 추가 -> (7, 5)에 추가
    RemoteController controller = {};
    PwrMgr_init(controller);

    PwrMgr_putPowerSupply(1,2);
    PwrMgr_putPowerSupply(9,9);
    PwrMgr_removePowerSupply(3,3);
    PwrMgr_putPowerSupply(2,7);
    PwrMgr_putPowerSupply(7,5);

}

// TODO: (문제2-2)
// 초기 상황에서 (7, 7)에 전력 공급장치를 추가 했을 때
// 전력이 공급된 장비에 기동 신호를 보내는지(RemoteController#on API를 제대로 호출하는지)
// 확인하는 테스트 코드를 작성하시오. (해당 장비에 기동 신호를 보내지 않을 경우 테스트 실패 처리가 되도록)

// 단, 예상(기대) 결과와 같은지 확인하는 verify API는 반드시 아래의 API를 이용하도록 한다.

//void ASSERT_EQ(T expected, T actual); // expected와 actual이 같지 않으면 테스트 실패 처리
// example: ASSERT_EQ(5, add(2, 3)); // add(2, 3)가 5를  반환하는지 검증

// NOTE: 아래 함수를 여러 번 호출 할 수 있도록 초기화 등 테스트 코드 동작에 필요한 내용을 모두 포함해야 한다.

struct Position {
    int row;
    int col;
};
static struct Position onDevices_[20];
static int count_ = 0;

void onSpy(int row, int col) {
    Position pos = { row, col };
    onDevices_[count_++] = pos;
}

bool wasOn(int row, int col) {
    for (int i = 0; i < count_; i++) {
        if (onDevices_[i].row == row && onDevices_[i].col == col) {
            return true;
        }
    }
    return false;
}

void test_2_2()
{
    count_ = 0;
    RemoteController controller = {onSpy};
    PwrMgr_init(controller);

    PwrMgr_putPowerSupply(7,7);

    ASSERT_EQ(true, wasOn(6,6));
    ASSERT_EQ(true, wasOn(8,6));
    //ASSERT_EQ(기대, 실제);
}

/* [문제 3. 작성 내용] */
// 기능 요구사항에서 고려하지 못한 경우나 구현에서 예외처리를 하지 않은 예외 상황을 표현하는 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// NOTE: 테스트 케이스 당 한가지의 예외 상황을 표현해야 한다.
/* 테스트 케이스의 형식:
{
	{입력 갯수, {종류(PUT/REMOVE), 행,열}, ..., {종류(PUT/REMOVE), 행,열} },
		...
	{3, {PUT,7,7}, {PUT,4,1}, {REMOVE, 3, 3} } // 테스트 케이스 예: (7,7)와 (4,1)에 전력 공급 장치를 배치하고, (3,3)의 전력 공급 장치를 회수하는 경우
};
*/

// TODO: 문제 3
int numberOfCases = 4;
TestInput test_3_cases[4] = {
    {1, { {REMOVE,3,4} }}, // ERR_NOT_EXIST
    {1, { {PUT,2,8} }},     // ERR_INVALID_POSITION
    {11, { {REMOVE,3,3}, {PUT,1,1}, {PUT,4,1}, {PUT,1,4}, {PUT,1,7}, {PUT,3,6}, {PUT,3,9}, {PUT,5,4}, {PUT,5,8}
        , {PUT,7,7}, {PUT,8,5} }},  // ERR_OVER_COUNT
    {1, { {PUT, 20,20} } },    // ERR_OUT_OF_RANGE
};

// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점 시 실행되지 않는다.
int main()
{
    powerTestInputResult("Sample Input", sampleInput_case);

    powerTestInputResult("Test_1_1 Input", test_1_1_case);
    powerTestInputResult("Test_1_2 Input", test_1_2_case);
    powerTestInputResult("Test_1_3 Input", test_1_3_case);

    test_2_1();
    test_2_2();

    powerTestInputResult("Test_3", test_3_cases[0]);
    //powerTestInputResult("Test_3", test_3_cases[1]);
    //powerTestInputResult("Test_3", test_3_cases[2]);
    //powerTestInputResult("Test_3", test_3_cases[3]);

    return 0;
}