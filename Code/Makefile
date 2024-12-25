# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -I C:\Users\HP\Desktop\fltk\include

# Linker Flags
LDFLAGS = -L C:\Users\HP\Desktop\fltk\lib -lfltk -lcomctl32 -lole32 -luuid -lgdi32 -lws2_32 -lgdiplus -lwinspool -lcomdlg32

# Target
TARGET = ExpenseTracker.exe

# Source Files
SRCS = main.cpp ExpenseTracker.cpp GuiManager.cpp StartScreenGroup.cpp LoginGroup.cpp RegisterGroup.cpp \
MainApplicationGroup.cpp User.cpp HomepageGroup.cpp AddGroup.cpp ReportGroup.cpp Date.cpp Expense.cpp ExpenseTable.cpp \
Income.cpp IncomeTable.cpp Budget.cpp



# Build Rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	del $(TARGET)
