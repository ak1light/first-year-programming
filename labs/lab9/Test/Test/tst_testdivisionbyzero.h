#ifndef TST_TESTDIVISIONBYZERO_H
#define TST_TESTDIVISIONBYZERO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <lockcontroller.h>
#include <IKeypad.h>
#include <ILatch.h>
using namespace testing;


class MockIKeypad : public IKeypad
{
public:
    MOCK_METHOD(bool, isActive,(),(override));
    MOCK_METHOD(void, wait,(),(override));
    MOCK_METHOD(PasswordResponse, requestPassword,(),(override));
};
class MockILatch : public ILatch
{
public:
    MOCK_METHOD(bool, isActive,(),(override));
    MOCK_METHOD(DoorStatus, open,(),(override));
    MOCK_METHOD(DoorStatus, close,(),(override));
    MOCK_METHOD(DoorStatus, getDoorStatus,(),(override));
};

TEST(LockController, WAIT) // 1 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    // Act
    EXPECT_CALL(keypad, wait()).Times(1).WillOnce(Return());
    lock->wait();
    //__________
    delete lock;
}
TEST(LockController, DOORCLOSED)//2 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    EXPECT_CALL(latch, getDoorStatus()).Times(1).WillOnce(Return(DoorStatus::CLOSE));
    // Act


    bool result = lock->isDoorOpen();
    // Assert
    ASSERT_FALSE(result);
    //__________
    delete lock;
}
TEST(LockController, DOOROPEN) // 3 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    EXPECT_CALL(latch, getDoorStatus()).Times(1).WillOnce(Return(DoorStatus::OPEN));
    // Act
    bool result = lock->isDoorOpen();
    // Assert
    ASSERT_TRUE(result);
    //__________
    delete lock;
}
TEST(LockController, UNLOCKDOOR) // 4 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    EXPECT_CALL(latch, open()).Times(1).WillOnce(Return(DoorStatus::OPEN));
    // Act
    DoorStatus res = lock->unlockDoor();
    // Assert
    ASSERT_EQ(res, DoorStatus::OPEN);
    //_________
    delete lock;

}
TEST(LockController, LOCKDOOR) // 5 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    EXPECT_CALL(latch, open()).Times(1).WillOnce(Return(DoorStatus::OPEN));
    // Act
    DoorStatus res = lock->lockDoor();
    // Assert
    ASSERT_EQ(res, DoorStatus::CLOSE);
    //_________
    delete lock;
}
TEST(LockController, CHECKHARDWARE_OK) // 6 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    EXPECT_CALL(keypad, isActive()).Times(1).WillOnce(Return(true));
    EXPECT_CALL(latch, isActive()).Times(1).WillOnce(Return(true));
    // Act
    HardWareStatus res = lock->hardWareCheck();
    // Assert
    ASSERT_EQ(res, HardWareStatus::OK);
    //_________
    delete lock;
}
TEST(LockController, CHECKHARDWARE_KEYPAD_ERROR) // 7 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(nullptr, &latch);
    EXPECT_CALL(keypad, isActive()).Times(AtLeast(0)).WillOnce(Return(true));
    EXPECT_CALL(latch, isActive()).Times(AtLeast(0)).WillOnce(Return(true));
    // Act
    HardWareStatus res = lock->hardWareCheck();
    // Assert
    ASSERT_EQ(res, HardWareStatus::ERROR);
    //_________
    delete lock;
}
TEST(LockController, CHECKHARDWARE_LATCH_ERROR) // 8 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    EXPECT_CALL(keypad, isActive()).Times(AtLeast(0)).WillOnce(Return(true));
    EXPECT_CALL(latch, isActive()).Times(AtLeast(0)).WillOnce(Return(false));
    // Act
    HardWareStatus res = lock->hardWareCheck();
    // Assert
    ASSERT_EQ(res, HardWareStatus::ERROR);
    //_________
    delete lock;
}
TEST(LockController, PASSWORD_CHECK_OK) // 9 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    PasswordResponse pr;
    pr.status = PasswordResponse::Status::OK;
    pr.password = "0000";
    EXPECT_CALL(keypad, requestPassword()).Times(AtLeast(0)).WillOnce(Return(pr));
    // Act
    bool res = lock->isCorrectPassword();
    // Assert
    ASSERT_TRUE(res);
    //_________
    delete lock;
}
TEST(LockController, PASSWORD_CHECK_WRONG) // 10 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);
    PasswordResponse pr;
    pr.status = PasswordResponse::Status::OK;
    pr.password = "1111";
    EXPECT_CALL(keypad, requestPassword()).Times(AtLeast(0)).WillOnce(Return(pr));
    // Act
    bool res = lock->isCorrectPassword();
    // Assert
    ASSERT_FALSE(res);
    //_________
    delete lock;
}
TEST(LockController, PASSWORD_CHECK_RESET) // 11 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);

    PasswordResponse pr;
    pr.status = PasswordResponse::Status::OK;
    pr.password = "0000";

    PasswordResponse pr1;
    pr1.status = PasswordResponse::Status::OK;
    pr1.password = "1111";

    PasswordResponse pr2;
    pr2.status = PasswordResponse::Status::OK;
    pr2.password = "1111";

    EXPECT_CALL(keypad, requestPassword()).Times(3).WillOnce(Return(pr)).WillOnce(Return(pr1)).WillOnce(Return(pr2));
    lock->resetPassword();
    // Act
    bool res = lock->isCorrectPassword();
    // Assert
    ASSERT_TRUE(res);
    //_________
    delete lock;
}
TEST(LockController, PASSWORD_CHECK_RESET_TWICE) // 12 тест
{
    // Arrange
    MockIKeypad keypad;
    MockILatch latch;
    LockController *lock = new LockController(&keypad, &latch);

    PasswordResponse pr;
    pr.status = PasswordResponse::Status::OK;
    pr.password = "0000";

    PasswordResponse pr1;
    pr1.status = PasswordResponse::Status::OK;
    pr1.password = "9876";

    PasswordResponse pr2;
    pr2.status = PasswordResponse::Status::OK;
    pr2.password = "9876";

    PasswordResponse pr3;
    pr3.status = PasswordResponse::Status::OK;
    pr3.password = "1111";

    PasswordResponse pr4;
    pr4.status = PasswordResponse::Status::OK;
    pr4.password = "1111";

    EXPECT_CALL(keypad, requestPassword()).Times(5).WillOnce(Return(pr)).WillOnce(Return(pr1)).WillOnce(Return(pr2)).WillOnce(Return(pr3)).WillOnce(Return(pr4));
    lock->resetPassword();
    lock->resetPassword();
    // Act
    bool res = lock->isCorrectPassword();
    // Assert
    ASSERT_TRUE(res);
    //_________
    delete lock;
}
#endif // TST_TESTDIVISIONBYZERO_H
