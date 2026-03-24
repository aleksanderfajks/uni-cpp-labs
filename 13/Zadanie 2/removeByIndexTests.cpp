#include "gtest/gtest.h"
#include "removeByIndex.h"

TEST(removeByIndexTests, removeIndex0FromEmptyList) {
    //Pusta lista — usuwanie węzła o indeksie 0
    Node_t *root = NULL;
    removeByIndex(&root, 0);
    EXPECT_EQ(root, nullptr);
}

TEST(removeByIndexTests, removeOtherIndexFromEmptyList) {
    //Pusta lista — usuwanie węzła o indeksie większym niż 0
    Node_t *root = NULL;
    removeByIndex(&root, 1);
    EXPECT_EQ(root, nullptr);
}

TEST(removeByIndexTests, removeIndex0FromSingleElementList) {
    //Lista jednoelementowa — usuwanie węzła o indeksie 0
    Node_t *root = NULL;
    pushBack(&root, 1);
    removeByIndex(&root, 0);
    EXPECT_EQ(root, nullptr);
    deleteList(&root);
}

TEST(removeByIndexTests, removeOtherIndexFromSingleElementList) {
    //Lista jednoelementowa — usuwanie węzła o indeksie większym niż 0
    Node_t *root = NULL;
    pushBack(&root, 1);
    removeByIndex(&root, 5);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->head, 1);
    EXPECT_EQ(root->tail, nullptr);
    deleteList(&root);
}

TEST(removeByIndexTests, removeIndex0FromMultiElementList) {
    //Lista n-elementowa — usuwanie węzła o indeksie 0;
    Node_t *root = NULL;
    pushBack(&root, 1);
    pushBack(&root, 2);
    pushBack(&root, 3);
    removeByIndex(&root, 0);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->head, 2);
    EXPECT_NE(root->tail, nullptr);
    EXPECT_EQ(root->tail->head, 3);
    EXPECT_EQ(root->tail->tail, nullptr);
    deleteList(&root);
}

TEST(removeByIndexTests, removeIndex1FromMultiElementList) {
    //Lista n-elementowa — usuwanie węzła o indeksie 1;
    Node_t *root = NULL;
    pushBack(&root, 1);
    pushBack(&root, 2);
    pushBack(&root, 3);
    removeByIndex(&root, 1);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->head, 1);
    EXPECT_NE(root->tail, nullptr);
    EXPECT_EQ(root->tail->head, 3);
    EXPECT_EQ(root->tail->tail, nullptr);
    deleteList(&root);
}

TEST(removeByIndexTests, removeIndexAfterLastFromMultiElementList) {
    //Lista n-elementowa — usuwanie węzła o indeksie n+1;
    Node_t *root = NULL;
    pushBack(&root, 1);
    pushBack(&root, 2);
    pushBack(&root, 3);
    removeByIndex(&root, 5);
    ASSERT_NE(root, nullptr);
    EXPECT_EQ(root->head, 1);
    EXPECT_NE(root->tail, nullptr);
    EXPECT_EQ(root->tail->head, 2);
    EXPECT_NE(root->tail->tail, nullptr);
    EXPECT_EQ(root->tail->tail->head, 3);
    EXPECT_EQ(root->tail->tail->tail, nullptr);
    deleteList(&root);
}