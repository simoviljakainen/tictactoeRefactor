#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <stdlib.h>
#include <string.h>

#include "players.h"

/* Test functions */

void test_player_input(void){
	freopen("testinput.txt", "r", stdin);
	CU_ASSERT_EQUAL(player_input(), 8);
	CU_ASSERT(getchar() == '\n');
	
}

void test_avoid_reading_more_chars(void){
	freopen("testinput.txt", "r", stdin);
	avoid_reading_more_chars();
	CU_ASSERT_EQUAL(getchar(), '\n');
}

void test_index_of_input(void){
	CU_ASSERT_EQUAL(index_of_input('q'), 0);
	CU_ASSERT_EQUAL(index_of_input('w'), 1);
	CU_ASSERT_EQUAL(index_of_input('e'), 2);
	CU_ASSERT_EQUAL(index_of_input('a'), 3);
	CU_ASSERT_EQUAL(index_of_input('s'), 4);
	CU_ASSERT_EQUAL(index_of_input('d'), 5);
	CU_ASSERT_EQUAL(index_of_input('z'), 6);
	CU_ASSERT_EQUAL(index_of_input('x'), 7);
	CU_ASSERT_EQUAL(index_of_input('c'), 8);
	CU_ASSERT_EQUAL(index_of_input('p'), -1);
	CU_ASSERT_EQUAL(index_of_input('b'), -1);
	CU_ASSERT_EQUAL(index_of_input('o'), -1);
	CU_ASSERT_EQUAL(index_of_input('m'), -1);
}


void test_make_move(void){
	char board[ROWS][COLUMNS] =
  {
    {'o', 'x', 'o'},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };

	CU_ASSERT_EQUAL(make_move(board,'x',5 ), 1);
	CU_ASSERT_EQUAL(make_move(board,'o',4 ), 1);
	CU_ASSERT_EQUAL(make_move(board,'x',2 ), 0);
	CU_ASSERT_EQUAL(make_move(board,'o',0 ), 0);

}


int main(void){

	/*Init registry*/
	if(CU_initialize_registry()==CUE_SUCCESS){
		printf("\nRegistry initialization was successful.\n\n");	
	}else{
		printf("\nRegistry initialization failed.\n\n");
		exit(1);	
	}
	
	/*Add suites and tests*/
	
	CU_TestInfo tests_playerModule[] = {
	{"testInput",test_player_input},
	{"testReads",test_avoid_reading_more_chars},
	{"testIndex",test_index_of_input},
	{"testMove",test_make_move},
	CU_TEST_INFO_NULL,};
	
	CU_SuiteInfo playerModuleSuites[] = {
	{"playerModule_test_suite",NULL, NULL,NULL,NULL, tests_playerModule},
	CU_SUITE_INFO_NULL,};

	if(CU_register_suites(playerModuleSuites)==CUE_SUCCESS){
		printf("Suite was created and tests were added successfully.\n");	
	}else{
		printf("Suite creation failed.\n'%s'\n",CU_get_error_msg());
		CU_cleanup_registry();
		exit(1);	
	}

	CU_automated_run_tests();

	/* Summary */
	CU_pRunSummary summary = CU_get_run_summary();
		
	printf("\n\n--------Testing completed--------\n\nSuites ran\t%u\nSuites failed\t%u\n\
Tests ran\t%u\nTests failed\t%u\nAsserts ran\t%u\nAsserts failed\t%u\n",
			summary->nSuitesRun,summary->nSuitesFailed,summary->nTestsRun,
			summary->nTestsFailed,summary->nAsserts, summary->nAssertsFailed);

	/* Get failures */
	CU_pFailureRecord failureRecord = CU_get_failure_list();

	if(failureRecord != NULL){

		printf("\n--------Failure records--------\n\n");
		printf("CONDITION\t\tTEST\t\tSUITE\t\tLINE\n\n");

		while(failureRecord !=NULL){

			printf("%s\t%s\t%s\t%u\n",failureRecord->strCondition, failureRecord->pTest->pName, 					failureRecord->pSuite->pName, failureRecord->uiLineNumber);

			failureRecord = failureRecord->pNext;		
		}

		printf("\n");

	}else{
		printf("\nApplication PASSED all the tests.\n\n");
	}
	
	/* Cleanup */
	CU_cleanup_registry();

	return(0);
}
