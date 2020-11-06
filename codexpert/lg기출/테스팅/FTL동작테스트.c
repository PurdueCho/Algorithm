#include <cstdio>
#include <cstring>

#include <locale>

#include "./lib/FTLayer.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다.
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 케이스 입력과 테스트 코드를 작성하시오.
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

/**
 * 상수 정의
 *
#define MAX_REQ_LIMIT	(50)
#define MAX_BLOCK_COUNT	(8)

#define W 1 // Write(쓰기)
#define M 2 // Modify(수정)
#define R 3 // Read(읽기)
#define D 4 // Delete(삭제)

/**
 * Request class
 * 요청 데이터 구조
 *
struct Request {
	int operation;  // W, M, R, D 중 하나 
	int block;
	int length;
};



/**
 * FlashMemory 인터페이스
 * 플래시 메모리의 물리 블록에 읽기, 쓰기, 삭제 동작을 수행하도록 지시하는 인터페이스
 * 각 동작에 해당하는 처리 함수를 지정하는 함수포인터를 포함하고 있다.
 *
 *
struct FlashMemory
{
	BOOL(*write)(int blockNumber/*, const BlockData* data* /); // 데이터는 편의상 생략 
	BOOL(*read)(int blockNumber/*, BlockData* data* /); // 데이터는 편의상 생략 
	BOOL(*erase)(int blockNumber);
};



/**
 * [테스트 대상] FTL 모듈
 * 논리 블록에 대한 요청을 받아 상황에 따라 적절한 물리 블록에 요청 동작을 수행 (테스트 대상)
 *
 *

static FlashMemory flashMemory_;

static int mappingStatus_[MAX_BLOCK_COUNT];
static int physicalStatus_[MAX_BLOCK_COUNT];
static int eraseStatus_[MAX_BLOCK_COUNT];
static int freeBlockCount_ = MAX_BLOCK_COUNT;

static BOOL hasFreeLogicalBlock(int start, int length);
static BOOL isUsedLogicalBlock(int start, int length);
static int findFreePhysicalBlock(int length);
static void resetStatus();


/**
 * FTL 모듈을 초기화
 *
 * @param flashMemory 플래시 메모리의 물리 블록에 동작을 지시하는 제어 인터페이스
 *
void FTL_init(FlashMemory flashMemory)
{
	flashMemory_ = flashMemory;
	resetStatus();
}

static void resetStatus()
{
	for (int i = 0; i < MAX_BLOCK_COUNT; i++) {
		mappingStatus_[i] = -1;
		physicalStatus_[i] = 0;
		eraseStatus_[i] = 0;
	}
	freeBlockCount_ = MAX_BLOCK_COUNT;
}

/**
 * 요청한 논리 블록에 쓰기 동작을 수행
 * @param start 쓰기 동작을 시작할 논리 블록 번호
 * @param length 쓰기 동작을 수행할 블록 갯수
 *
Bool FTL_writeBlock(int start, int length)
{
	if (!hasFreeLogicalBlock(start, length))
		return FALSE;

	int firstFreeBlock = findFreePhysicalBlock(length);
	if (firstFreeBlock < 0)
		return FALSE;

	int block = firstFreeBlock;
	for (int i = start; i < start + length; i++) {
		eraseStatus_[block]++;
		mappingStatus_[i] = block;
		physicalStatus_[block] = 1;
		block++;
	}

	freeBlockCount_ -= length;
	
	for (int i = 0; i < length; ++i) {
		flashMemory_.erase(mappingStatus_[start + i]);
		flashMemory_.write(mappingStatus_[start + i]);
	}

	return TRUE;
}

/**
 * 요청한 논리 블록을 수정하는 동작을 수행
 * @param start 수정 동작을 시작할 논리 블록 번호
 * @param length 수정 동작을 수행할 블록 갯수
 *
BOOL FTL_modifyBlock(int start, int length)
{
	if (!isUsedLogicalBlock(start, length))
		return FALSE;

	int firstFreeBlock = findFreePhysicalBlock(length);
	if (firstFreeBlock < 0)
		return FALSE;

	int block = firstFreeBlock;
	for (int i = start; i < start + length; i++) {
		eraseStatus_[block]++;
		physicalStatus_[mappingStatus_[i]] = 0;
		mappingStatus_[i] = block;
		physicalStatus_[block] = 1;
		block++;
	}

	for (int i = 0; i < length; ++i) {
		flashMemory_.erase(mappingStatus_[start + i]);
		flashMemory_.write(mappingStatus_[start + i]);
	}
	
	return TRUE;
}

/**
 * 요청한 논리 블록의 내용을 읽어오는 동작을 수행
 * @param start 읽기 동작을 시작할 논리 블록 번호
 * @param length 읽기 동작을 수행할 블록 갯수
 *
BOOL FTL_readBlock(int start, int length)
{
	if (!isUsedLogicalBlock(start, length))
		return FALSE;

	for (int i = 0; i < length; ++i) {
		flashMemory_.read(mappingStatus_[start + i]);
	}

	return TRUE;
}

/**
 * 사용하지 않을 논리 블록을 해제
 * @param start 삭제 동작을 시작할 논리 블록 번호
 * @param length 삭제 동작을 수행할 블록 갯수
 *
BOOL FTL_deleteBlock(int start, int length)
{
	if (!isUsedLogicalBlock(start, length))
		return FALSE;

	for (int i = start; i < start + length; i++) {
		physicalStatus_[mappingStatus_[i]] = 0;
		mappingStatus_[i] = -1;
	}
	freeBlockCount_ += length;

	return TRUE;
}

static int getFreeBlockCount()
{
	return freeBlockCount_;
}

// start 부터 count 개의 논리 블록이 모두 사용 중이면 TRUE
static BOOL isUsedLogicalBlock(int start, int count)
{
	for (int i = start; i < start + count; i++) {
		if (mappingStatus_[i] == -1) {
			return FALSE;
		}
	}
	return TRUE;
}

// start 부터 count 개의 논리 블록이 모두 비어 있으면 TRUE
static BOOL hasFreeLogicalBlock(int start, int count)
{
	for (int i = start; i < start + count; i++) {
		if (mappingStatus_[i] != -1) {
			return FALSE;
		}
	}
	return TRUE;
}

// count 개의 연속된 비어 있는 물리 블록을 앞에서부터 검색하여 찾으면 시작하는 물리 블록을 반환, 못 찾으면 -1을 반환
static int findFreePhysicalBlock(int count)
{
	for (int i = 0; i <= MAX_BLOCK_COUNT - count; i++) {
		int j = 0;
		for (j = i; j < i + count; j++) {
			if (physicalStatus_[j] == 1) break;
		}
		if (j == i + count) {
			return i;
		}
	}

	return -1;
}


struct RequestSequence {
	int length;
	Request requests[MAX_REQ_LIMIT];
};
*/

/* [문제 1. 작성 내용] */
// 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 형식: { 입력길이 N, { 입력 요청 값 1, 입력 요청 값 2, ... , 입력 요청 값 N } }

// 테스트 케이스 예) : 문제에서 설명한 동작 예제
// 요청이 {W,0,6}, {D,3,2}, {M,1,2} ,{R,0,3} 순으로 입력되는 경우
RequestSequence sampleInput_reqs = {
    4,
    {{W, 0, 6}, {D, 3, 2}, {M, 1, 2}, {R, 0, 3}}};

//TODO: 문제1.(1-1) - 최종적으로 비어 있는 물리 블록이 0개가 되는 상황
RequestSequence test_1_1_reqs = {
    6,
    { {W,0,6}, {D,3,2}, {M,1,2}, {R,0,3}, {W,3,2}, {W,6,2} }
};

//TODO: 문제1.(1-2) - 최종적으로 비어 있는 물리 블록이 4개이고, 0번 ~ 3번 물리 블록이 비어 있는 상황
RequestSequence test_1_2_reqs = {
    8,
    { {W,0,6}, {D,3,2}, {M,1,2}, {R,0,3}, {W,3,2}, {W,6,2}, {D,0,2}, {D,3,2} }
};

//TODO: 문제1.(1-3) - 최종적으로 물리 블록의 지운 회수가 모두 2가 되는 상황
RequestSequence test_1_3_reqs = {
    10,
    { {W,0,6}, {D,3,2}, {M,1,2}, {R,0,3}, {W,3,2}, {W,6,2}, {D,0,1}, {W,0,1}, {D,5,3}, {W,5,3} }
};

//TODO: 문제1. (1-4) - FTL의 모듈 코드에 대해서 statement coverage 100%가 만족되는 요청 입력
RequestSequence test_1_4_reqs = {
    15,
    { {R,7,1}, {D,7,1}, {M,0,5}, {W,0,8}, {W,0,6}, {D,0,8}, {W,0,4}, {M,0,2}, {W,4,4}, {M,0,4}, {D,0,4},
      {W,0,6}, {D,3,2}, {M,1,2}, {R,0,3} }
};

// [문제2. 작성 내용]
// NOTE: 답안 코드 실행 중 메모리 누수나 런타임 에러가 발생하면 오답 처리됨

static BOOL writeDummy(int blockNumber) {return false;}

int lastReadBlock_ = -1;

static BOOL readSpy(int blockNumber) {
    lastReadBlock_ = blockNumber;
    return true;
}

static BOOL eraseDummy(int blockNumber) {
    return false;
}

FlashMemory flashSpy = {
    writeDummy,
    readSpy,
    eraseDummy,
};

void FlashSpy_init() {
    lastReadBlock_ = -1;
}

void test_2_1()
{
    // TODO: // 문제2.(2-1)
    // 요청이 다음의 순서대로 발생하는 상황: W,1,4 -> R,2,2 -> M,4,1 -> D,1,1
    FlashSpy_init();
    FTL_init(flashSpy);

    FTL_writeBlock(1,4);
    FTL_readBlock(2,2);
    FTL_modifyBlock(4,1);
    FTL_deleteBlock(1,1);
}

void test_2_2()
{
    // TODO: 문제2.(2-2)
    // 요청이 다음의 순서대로 발생하는 상황: W,0,8 -> D,6,2 -> M,4,2 -> R,2,2 -> D,2,2

    FlashSpy_init();
    FTL_init(flashSpy);

    FTL_writeBlock(0,8);
    FTL_deleteBlock(6,2);
    FTL_modifyBlock(4,2);
    FTL_readBlock(2,2);
    FTL_deleteBlock(2,2);
}

// [문제3. 작성 내용]
/**
 * FTLExt 모듈
 * 
 */
static FlashMemory flashController_;

static int blockTable_[MAX_BLOCK_COUNT];
static int usedPhysicalBlock_[MAX_BLOCK_COUNT];
static int eraseCount_[MAX_BLOCK_COUNT];
static int ext_freeBlocks = MAX_BLOCK_COUNT;

static BOOL hasFreeLogicalBlock_ext(int start, int length);
static BOOL isUsedLogicalBlock_ext(int start, int length);
static int findFreePhysicalBlock_ext(int length);
static void resetStatus_ext();

/**
 * FTLExt 모듈을 초기화
 * @param flashMemory 플래시 메모리의 물리 블록에 동작을 지시하는 제어 인터페이스
 */
void FTLExt_init(FlashMemory flashMemory)
{
    flashController_ = flashMemory;
    resetStatus_ext();
}

static void resetStatus_ext()
{
    for (int i = 0; i < MAX_BLOCK_COUNT; i++)
    {
        blockTable_[i] = -1;
        usedPhysicalBlock_[i] = 0;
        eraseCount_[i] = 0;
    }
    ext_freeBlocks = MAX_BLOCK_COUNT;
}

/**
 * 요청한 논리 블록에 쓰기 동작을 수행
 * @param start 쓰기 동작을 시작할 논리 블록 번호
 * @param length 쓰기 동작을 수행할 블록 갯수
 */
BOOL FTLExt_writeBlock(int start, int length)
{
    if (!hasFreeLogicalBlock_ext(start, length))
        return FALSE;

    int firstFreeBlock = findFreePhysicalBlock_ext(length);
    if (firstFreeBlock < 0)
        return FALSE;

    int block = firstFreeBlock;
    for (int i = start; i < start + length; i++)
    {
        eraseCount_[block]++;
        blockTable_[i] = block;
        usedPhysicalBlock_[block] = 1;
        block++;
    }

    ext_freeBlocks -= length;

    for (int i = 0; i < length; ++i)
    {
        flashController_.erase(blockTable_[start + i]);
        flashController_.write(blockTable_[start + i]);
    }

    return TRUE;
}

/**
 * 요청한 논리 블록을 수정하는 동작을 수행
 * @param start 수정 동작을 시작할 논리 블록 번호
 * @param length 수정 동작을 수행할 블록 갯수
 */
BOOL FTLExt_modifyBlock(int start, int length)
{
    if (!isUsedLogicalBlock_ext(start, length))
        return FALSE;

    int firstFreeBlock = findFreePhysicalBlock_ext(length);
    if (firstFreeBlock < 0)
        return FALSE;

    int block = firstFreeBlock;
    for (int i = start; i < start + length; i++)
    {
        eraseCount_[block]++;
        usedPhysicalBlock_[blockTable_[i]] = 0;
        blockTable_[i] = block;
        usedPhysicalBlock_[block] = 1;
        block++;
    }

    for (int i = 0; i < length; ++i)
    {
        flashController_.erase(blockTable_[start + i]);
        flashController_.write(blockTable_[start + i]);
    }

    return TRUE;
}

/**
 * 요청한 논리 블록의 내용을 읽어오는 동작을 수행
 * @param start 읽기 동작을 시작할 논리 블록 번호
 * @param length 읽기 동작을 수행할 블록 갯수
 */
BOOL FTLExt_readBlock(int start, int length)
{
    if (!isUsedLogicalBlock_ext(start, length))
        return FALSE;

    for (int i = 0; i < length; ++i)
    {
        flashController_.read(blockTable_[start + i]);
    }

    return TRUE;
}

/**
 * 사용하지 않을 논리 블록을 해제
 * @param start 삭제 동작을 시작할 논리 블록 번호
 * @param length 삭제 동작을 수행할 블록 갯수
 */
BOOL FTLExt_deleteBlock(int start, int length)
{
    if (!isUsedLogicalBlock_ext(start, length))
        return FALSE;

    for (int i = start; i < start + length; i++)
    {
        usedPhysicalBlock_[blockTable_[i]] = 0;
        blockTable_[i] = -1;
    }
    ext_freeBlocks += length;

    return TRUE;
}

static BOOL isUsedLogicalBlock_ext(int start, int count)
{
    for (int i = start; i < start + count; i++)
    {
        if (blockTable_[i] == -1)
        {
            return FALSE;
        }
    }
    return TRUE;
}

// start 부터 count 개의 논리 블록이 모두 비어 있으면 TRUE
static BOOL hasFreeLogicalBlock_ext(int start, int count)
{
    for (int i = start; i < start + count; i++)
    {
        if (blockTable_[i] != -1)
        {
            return FALSE;
        }
    }
    return TRUE;
}

int calSum(int *p, int start, int count) {
    int sum = 0;

    for (int i = start; i < start + count; i++) {
        sum += p[i];
    }
    return sum;
}

// count 개의 연속된 비어 있는 물리 블록을 앞에서부터 검색하여 찾으면 시작하는 물리 블록을 반환, 못 찾으면 -1을 반환
static int findFreePhysicalBlock_ext(int count)
{
    int i , j;
    int found = 0, sum, min_sum = 0x7fffffff, min_block = -1;
    for (i = 0 ; i <= MAX_BLOCK_COUNT - count; i++) {
        for (j = i ; j < i + count ; j++) {
            if (usedPhysicalBlock_[j] == 1) break;
        }
        if (j == i + count) {
            sum = calSum(eraseCount_, i , count);
            if (sum < min_sum) {
                found = 1;
                min_sum = sum;
                min_block = i;
            }
        }
    }
    if (found) {
        return min_block;
    }

    return -1;
}

// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점과 관련이 없다.
int main()
{
    printTestInputResult("Sample Input", &sampleInput_reqs);
    printTestInputResult("Test_1_1 Input", &test_1_1_reqs);
    printTestInputResult("Test_1_2 Input", &test_1_2_reqs);
    printTestInputResult("Test_1_3 Input", &test_1_3_reqs);

    test_2_1();
    test_2_2();

    return 0;
}