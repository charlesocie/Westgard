# CMake generated Testfile for 
# Source directory: /home/charles/Desktop/Westguard-SSM
# Build directory: /home/charles/Desktop/Westguard-SSM
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AllTest "/home/charles/Desktop/Westguard-SSM/src/test/Test" "--gtest_output=xml:gtest_report.xml")
subdirs("third_parties/googletest")
subdirs("third_parties/Markup")
subdirs("src")
