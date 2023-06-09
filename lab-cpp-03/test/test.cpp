/**
 * @file test.cpp
 * @brief 
 *
 * @author Davydov V.
 * @date 30-jul-2022
 * @version 1.0
 */

#include "list.h"
#include "entity.h"
#include <fstream>
#include <sstream>

#include <gtest/gtest.h>

using namespace std;

TEST(ProgramingLab03, AddBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  ASSERT_EQ(list.getNum_birds(), 2);
}

TEST(ProgramingLab03, DeleteBird) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");

  list.addBird(bird1);
  list.addBird(bird2);

  list.deleteBird(0);

  ASSERT_EQ(list.getNum_birds(), 1);
  ASSERT_EQ(list.getBird(0).getType(), bird2.getType());
}

TEST(ProgramingLab03, GenderRatio) {
  List list;
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2(false, "Robin", 8, 80, 18, 1, false, "woman");
  Bird bird3(true, "Finch", 10, 90, 15, 3, true, "woman");

  list.addBird(bird1);
  list.addBird(bird2);
  list.addBird(bird3);

  float genderRatio = list.get_gender_ratio();

  ASSERT_FLOAT_EQ(genderRatio, 66.66666f);
}

// Helper function to compare the contents of two files
bool compareFiles(const std::string& filename1, const std::string& filename2) {
  std::ifstream file1(filename1);
  std::ifstream file2(filename2);

  if (!file1.is_open() || !file2.is_open()) {
    return false;
  }

  std::string line1, line2;

  while (std::getline(file1, line1) && std::getline(file2, line2)) {
    if (line1 != line2) {
      return false;
    }
  }

  return file1.eof() && file2.eof();
}

  string createTempFile(const std::string& content) {
  ostringstream oss;
  oss << "temp_file_" << testing::UnitTest::GetInstance()->random_seed() << ".txt";
  string filename = oss.str();

  ofstream file(filename);
  file << content;
  file.close();

  return filename;
}

TEST(ProgramingLab03, ReadFromFile) {
  string content = "3\n1 soroka 8 10 12 2 1 woman\n";
  content += "0 vorobej 5 20 10 3 0 man\n";
  content += "1 Sparrow 3 50 10 2 1 man\n";
  std::string filename = createTempFile(content);
  
  List birds;
  
  std::ifstream inputFile(filename);
  inputFile >> birds;
  inputFile.close();

  ASSERT_EQ(birds.getNum_birds(), 3);
  
  remove(filename.c_str());
}

TEST(ProgramingLab03, WriteToFile) {
  // Create a list and add some birds
  List list;
  Bird bird1(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  list.addBird(bird1);
  list.addBird(bird2);

  // Create a temporary file for writing
  std::string filename = createTempFile("");

  // Write the list to the file
  std::ofstream outputFile(filename);
  outputFile << list;  // Using the overloaded operator<< for List
  outputFile.close();

  // Read the contents of the written file
  std::ifstream inputFile(filename);
  std::stringstream buffer;
  buffer << inputFile.rdbuf();
  std::string fileContents = buffer.str();
  inputFile.close();

  // Define the expected content
  std::string expectedContent = "Bird 1:\n";
  expectedContent += "  Is ringed: 1\n";
  expectedContent += "  Type: Sparrow\n";
  expectedContent += "  Age: 3\n";
  expectedContent += "  Nest:\n";
  expectedContent += "    Area: 50\n";
  expectedContent += "    Height: 10\n";
  expectedContent += "    Number of feeders: 2\n";
  expectedContent += "    Has nest: 1\n";
  expectedContent += "  Gender: man\n\n";
  expectedContent += "Bird 2:\n";
  expectedContent += "  Is ringed: 1\n";
  expectedContent += "  Type: Sparrow\n";
  expectedContent += "  Age: 3\n";
  expectedContent += "  Nest:\n";
  expectedContent += "    Area: 50\n";
  expectedContent += "    Height: 10\n";
  expectedContent += "    Number of feeders: 2\n";
  expectedContent += "    Has nest: 1\n";
  expectedContent += "  Gender: man\n\n";

  // Perform assertions on the file contents
  ASSERT_EQ(fileContents, expectedContent);

  // Delete the temporary file
  remove(filename.c_str());
}

TEST(ProgramingLab03, AssigmentBird) {
  Bird bird1(true, "Sparrow", 12, 100, 20, 2, true, "man");
  Bird bird2 = bird1;

  ASSERT_EQ(bird1, bird2);
}

TEST(BirdTest, BirdEqual) {
  Bird bird1(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(1, "Sparrow", 3, 50, 10, 2, 1, "man");

  ASSERT_EQ(bird1, bird2);
}

TEST(BirdTest, BirdNotEQual) {
  Bird bird1(1, "Sparrow", 3, 50, 10, 2, 1, "man");
  Bird bird2(0, "Sparrow", 3, 50, 10, 2, 1, "man");

  ASSERT_NE(bird1, bird2);
}
