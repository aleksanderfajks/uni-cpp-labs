#include "gtest/gtest.h"
#include "dispatcher.h"

// Pomocnicza funkcja do zwalniania całej listy
void freeList(Node_t* root) {
    while (root) {
        Node_t* temp = root;
        root = root->tail;
        free(temp);
    }
}

TEST(DispatchTest, removesElementEqualToArgument) {
    Node_t* list = createList(5 , 2, 4, 6, 8, 10);
    ParsedCommand_t command = parseCommand("isEqual 2");

    dispatch(&list, command);

    ASSERT_NE(list, nullptr);
    EXPECT_EQ(list->head, 4);
    ASSERT_NE(list->tail, nullptr);
    EXPECT_EQ(list->tail->head, 6);
    ASSERT_NE(list->tail->tail, nullptr);
    EXPECT_EQ(list->tail->tail->head, 8);
    ASSERT_NE(list->tail->tail->tail, nullptr);
    EXPECT_EQ(list->tail->tail->tail->head, 10);
    EXPECT_EQ(list->tail->tail->tail->tail, nullptr);

    freeList(list);
}

TEST(DispatchTest, removesElementGreaterThanArgument) {
    Node_t* list = createList(5, 2, 4, 6, 8, 10);
    ParsedCommand_t command = parseCommand("isGreater 4");

    dispatch(&list, command);

    ASSERT_NE(list, nullptr);
    EXPECT_EQ(list->head, 2);
    ASSERT_NE(list->tail, nullptr);
    EXPECT_EQ(list->tail->head, 4);
    ASSERT_NE(list->tail->tail, nullptr);
    EXPECT_EQ(list->tail->tail->head, 8);
    ASSERT_NE(list->tail->tail->tail, nullptr);
    EXPECT_EQ(list->tail->tail->tail->head, 10);
    EXPECT_EQ(list->tail->tail->tail->tail, nullptr);

    freeList(list);
}

TEST(DispatchTest, removesElementsLessThanArgument) {
    Node_t* list = createList(5, 2, 4, 6, 8, 10);
    ParsedCommand_t command = parseCommand("isLess 10");

    dispatch(&list, command);

    ASSERT_NE(list, nullptr);
    EXPECT_EQ(list->head, 4);
    ASSERT_NE(list->tail, nullptr);
    EXPECT_EQ(list->tail->head, 6);
    ASSERT_NE(list->tail->tail, nullptr);
    EXPECT_EQ(list->tail->tail->head, 8);
    ASSERT_NE(list->tail->tail->tail, nullptr);
    EXPECT_EQ(list->tail->tail->tail->head, 10);
    EXPECT_EQ(list->tail->tail->tail->tail, nullptr);
    
    freeList(list);
}