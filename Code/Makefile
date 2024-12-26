# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -I ./include -I /usr/include/FL

# Linker Flags
LDFLAGS = -L /usr/lib -lfltk

# Target
TARGET = ExpenseTracker

# Source Files
SRCS = main.cpp ExpenseTracker.cpp GuiManager.cpp StartScreenGroup.cpp LoginGroup.cpp RegisterGroup.cpp \
MainApplicationGroup.cpp User.cpp HomepageGroup.cpp AddGroup.cpp ReportGroup.cpp Date.cpp Expense.cpp \
ExpenseTable.cpp Income.cpp IncomeTable.cpp Budget.cpp


# Object Files
OBJS = $(SRCS:.cpp=.o)

# Build Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)mdır