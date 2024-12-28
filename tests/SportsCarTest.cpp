#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{
    class SportsCartTest : public ::testing::Test
    {
    protected:
        void SetUp() override
        {
            executor.reset(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::SPORTS_CAR));
        }

        void TearDown() override {}

    protected:
        std::unique_ptr<Executor> executor;
    };

    // 测试输入: M
    TEST_F(SportsCartTest, should_return_x_plus_2_given_command_is_M_and_facing_is_E)
    {
        // given
        // when
        executor->Execute("M");
        // then
        const Pose target{2, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：BM
    TEST_F(SportsCartTest, should_return_x_minus_2_given_command_is_BM_and_facing_is_E)
    {
        executor->Execute("BM");
        const Pose target{-2, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：FM
    TEST_F(SportsCartTest, should_return_x_plus_4_given_command_is_FM_and_facing_is_E)
    {
        executor->Execute("FM");
        const Pose target{4, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：FBM
    TEST_F(SportsCartTest, should_return_x_minus_4_given_command_is_FBM_and_facing_is_E)
    {
        executor->Execute("FBM");
        const Pose target{-4, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：L
    TEST_F(SportsCartTest, should_return_y_plus_1_and_facing_N_given_command_is_L_and_facing_is_E)
    {
        executor->Execute("L");
        const Pose target{0, 1, 'N'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：BL
    TEST_F(SportsCartTest, should_return_y_plus_1_and_facing_S_given_command_is_BL_and_facing_is_E)
    {
        executor->Execute("BL");
        const Pose target{0, 1, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：FL
    TEST_F(SportsCartTest, should_return_x_plus_1_y_plus_1_and_facing_N_given_command_is_FL_and_facing_is_E)
    {
        executor->Execute("FL");
        const Pose target{1, 1, 'N'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：FBL
    TEST_F(SportsCartTest, should_return_x_minus_1_y_plus_1_and_facing_S_given_command_is_FBL_and_facing_is_E)
    {
        executor->Execute("FBL");
        const Pose target{-1, 1, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：R
    TEST_F(SportsCartTest, should_return_y_minus_1_and_facing_S_given_command_is_R_and_facing_is_E)
    {
        executor->Execute("R");
        const Pose target{0, -1, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：BR
    TEST_F(SportsCartTest, should_return_y_minus_1_and_facing_N_given_command_is_BR_and_facing_is_E)
    {
        executor->Execute("BR");
        const Pose target{0, -1, 'N'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：FR
    TEST_F(SportsCartTest, should_return_x_plus_1_y_minus_1_and_facing_S_given_command_is_FR_and_facing_is_E)
    {
        executor->Execute("FR");
        const Pose target{1, -1, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：FBR
    TEST_F(SportsCartTest, should_return_x_minus_1_y_minus_1_and_facing_N_given_command_is_FBR_and_facing_is_E)
    {
        executor->Execute("FBR");
        const Pose target{-1, -1, 'N'};
        ASSERT_EQ(target, executor->Query());
    }
}