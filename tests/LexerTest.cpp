#include "gtest/gtest.h"
#include "Lexer.h"

TEST(LexerTest, HandlesEmptyInput) {
    Lexer lexer("");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

TEST(LexerTest, HandlesWhitespaceOnly) {
    Lexer lexer("   \t\n");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

TEST(LexerTest, HandlesIdentifiers) {
    Lexer lexer("abc def");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Identifier);
    EXPECT_EQ(token.text, "abc");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Identifier);
    EXPECT_EQ(token.text, "def");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

TEST(LexerTest, HandlesNumbers) {
    Lexer lexer("123 456");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Number);
    EXPECT_EQ(token.text, "123");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Number);
    EXPECT_EQ(token.text, "456");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

TEST(LexerTest, HandlesOperators) {
    Lexer lexer("+ - * / %");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "+");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "-");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "*");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "/");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "%");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

TEST(LexerTest, HandlesMultiCharacterOperators) {
    Lexer lexer("++ -- <= >= == != && || << >> <<-=->>");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "++");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "--");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "<=");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, ">=");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "==");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "!=");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "&&");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "||");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "<<");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, ">>");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "<<-=->>");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

TEST(LexerTest, HandlesMixedInput) {
    Lexer lexer("abc 123 + -");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Identifier);
    EXPECT_EQ(token.text, "abc");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Number);
    EXPECT_EQ(token.text, "123");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "+");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Operator);
    EXPECT_EQ(token.text, "-");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

TEST(LexerTest, HandlesQuotedStrings) {
    Lexer lexer("\"hello\" \"world\"");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::QuotedString);
    EXPECT_EQ(token.text, "hello");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::QuotedString);
    EXPECT_EQ(token.text, "world");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

TEST(LexerTest, HandlesComments) {
    Lexer lexer("// this is a comment\nabc");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Comment);
    EXPECT_EQ(token.text, " this is a comment");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::Identifier);
    EXPECT_EQ(token.text, "abc");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, Lexer::TokenType::EndOfFile);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}