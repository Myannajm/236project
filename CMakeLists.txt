cmake_minimum_required(VERSION 3.20)
project(236project1_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(236project1_0 main.cpp Token.h Lexer.h Automaton.h ColonDash.cpp ColonDash.h Comment.cpp Comment.h Facts.cpp Facts.h ID.cpp ID.h Queries.cpp Queries.h Schemes.cpp Schemes.h String.cpp String.h Undefined.cpp Undefined.h Lexer.cpp Rules.cpp Rules.h AddAutomaton.h AddAutomaton.cpp ColonAutomaton.h ColonAutomaton.cpp CommaAutomaton.h CommaAutomaton.cpp LeftParenAutomaton.h LeftParenAutomaton.cpp MultiplyAutomaton.h MultiplyAutomaton.cpp PeriodAutomaton.h PeriodAutomaton.cpp QuestionMarkAuto.h QuestionMarkAuto.cpp RightParenAutomaton.cpp RightParenAutomaton.h Parser.cpp Parser.h DatalogProgram.h Rule.h Predicate.h Parameter.h endOf.h)
