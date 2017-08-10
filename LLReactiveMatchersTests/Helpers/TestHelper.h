#import <Foundation/Foundation.h>

#define EXP_SHORTHAND

#ifdef COCOAPODS
#import <Expecta/Expecta.h>
#else
#import "Expecta.h"
#endif
#import "FakeTestCase.h"
#import "EXPExpect+Test.h"


#ifdef USE_XCTEST

#import <XCTest/XCTest.h>
#define TEST_SUPERCLASS XCTestCase

#define assertPass(expr) \
XCTAssertNoThrow((expr))

#define assertFail(expr, message...) \
XCTAssertThrowsSpecificNamed(expr, NSException, ## message)

#define assertEquals(a, b) XCTAssertEqual((a), (b))
#define assertEqualObjects(a, b) XCTAssertEqualObjects((a), (b))
#define assertTrue(a) XCTAssertTrue((a))
#define assertFalse(a) XCTAssertFalse((a))
#define assertNil(a) XCTAssertNil((a))

#else

#define TEST_SUPERCLASS SenTestCase

#define assertPass(expr) \
STAssertNoThrow((expr), nil)

#define assertFail(expr, message) \
STAssertThrowsSpecificNamed((expr), NSException, (message), nil)

#define assertEquals(a, b) STAssertEquals((a), (b), nil)
#define assertEqualObjects(a, b) STAssertEqualObjects((a), (b), nil)
#define assertTrue(a) STAssertTrue((a), nil)
#define assertFalse(a) STAssertFalse((a), nil)
#define assertNil(a) STAssertNil((a), nil)

#endif


#define test_expect(a) [expect(a) test]
