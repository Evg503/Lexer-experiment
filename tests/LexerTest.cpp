#include "gtest/gtest.h"
#include "Lexer.h"

TEST(LexerTest, HandlesEmptyInput) {
    Lexer lexer("");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
    EXPECT_FALSE(lexer.hasMoreTokens());
}

TEST(LexerTest, HandlesWhitespaceOnly) {
    Lexer lexer("   \t\n");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, "   \t\n");
    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesIdentifiers) {
    Lexer lexer("abc def");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Identifier);
    EXPECT_EQ(token.text, "abc");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Identifier);
    EXPECT_EQ(token.text, "def");

    EXPECT_FALSE(lexer.hasMoreTokens());
    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesNumbers) {
    Lexer lexer("123 456");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Number);
    EXPECT_EQ(token.text, "123");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Number);
    EXPECT_EQ(token.text, "456");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesOperators) {
    Lexer lexer("+ - * / %");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "+");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "-");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "*");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "/");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "%");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesMultiCharacterOperators) {
    Lexer lexer("++ -- <= >= == != && || << >> <<-=->>");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "++");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "--");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "<=");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, ">=");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "==");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "!=");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "&&");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "||");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "<<");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, ">>");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "<<-=->>");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesMixedInput) {
    Lexer lexer("abc 123 + -");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Identifier);
    EXPECT_EQ(token.text, "abc");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Number);
    EXPECT_EQ(token.text, "123");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "+");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Operator);
    EXPECT_EQ(token.text, "-");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesQuotedStrings) {
    Lexer lexer("\"hello\" \"world\"");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::QuotedString);
    EXPECT_EQ(token.text, "hello");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::QuotedString);
    EXPECT_EQ(token.text, "world");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesComments) {
    Lexer lexer("// this is a comment\nabc");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Comment);
    EXPECT_EQ(token.text, "// this is a comment\n");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Identifier);
    EXPECT_EQ(token.text, "abc");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesComments2) {
    Lexer lexer("# this is a comment\n#second line");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Comment);
    EXPECT_EQ(token.text, "# this is a comment\n");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Comment);
    EXPECT_EQ(token.text, "#second line");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}

TEST(LexerTest, HandlesKeywords) {
    Lexer lexer("if abc return whileMe");
    auto token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Keyword);
    EXPECT_EQ(token.text, "if");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Identifier);
    EXPECT_EQ(token.text, "abc");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Keyword);
    EXPECT_EQ(token.text, "return");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Whitespace);
    EXPECT_EQ(token.text, " ");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::Identifier);
    EXPECT_EQ(token.text, "whileMe");

    token = lexer.nextToken();
    EXPECT_EQ(token.type, TokenType::EndOfFile);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}