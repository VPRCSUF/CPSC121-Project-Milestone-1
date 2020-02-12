// Vincent Phillip Rodriguez CPSC121-09

#include <fstream>
#include <iostream>

const int HOUR_LIMIT = 23;
const int MINUTES_LIMIT = 59;

bool load_file(const std::string & FILE)
{
  std::ifstream in_file;
  in_file.open(FILE);

  char colon;
  char end_time_colon;

  int start_hour;
  int start_minutes;
  int end_hour;
  int end_minutes;

  std::string course_name;
  std::string location;
  std::string schedule;

  if (!in_file)
  {
    std::cout << "Error: File does not exist.\n";
    return false;
  }

  while (in_file)
  {
    if (in_file >> course_name)
    {
      std::getline(in_file, course_name);

      if (std::getline(in_file, location))
      {
        if (std::getline(in_file, schedule))
        {
          if (schedule == "M" || schedule == "T" || schedule == "W" ||
              schedule == "H" || schedule == "F" || schedule == "S" ||
              schedule == "MW" || schedule == "MF" || schedule == "TH")
          {
            // CHECK THE START TIME
            if (in_file >> start_hour)
            {
              in_file >> colon;
              in_file >> start_minutes;

              if ((start_hour >= 0 && start_hour <= HOUR_LIMIT) &&
                  (start_minutes >= 0 && start_minutes <= MINUTES_LIMIT))
              {
                // CHECK THE END TIME
                if (in_file >> end_hour)
                {
                  in_file >> end_time_colon;
                  in_file >> end_minutes;

                  if ((end_hour >= 0 && end_hour <= HOUR_LIMIT) &&
                      (end_minutes >= 0 && end_minutes <= MINUTES_LIMIT))
                  {
                    // CHECK START AND END DIFFERENCE
                    if (start_hour >= end_hour)
                    {
                      if (start_minutes > end_minutes)
                      {
                        std::cout << "Error: The start time " << end_hour << ":"
                                  << end_minutes
                                  << " should happen before the end time "
                                  << start_hour << ":" << start_minutes
                                  << ".\n";
                        return false;
                      }

                      std::cout << "Error: The start time " << end_hour << ":"
                                << end_minutes
                                << " should happen before the end time "
                                << start_hour << ":" << start_minutes << ".\n";
                      return false;
                    }
                  }
                  else
                  {
                    std::cout << "Error: Unable to get a valid end time.\n";
                    std::cout << "Error: " << end_hour << ":" << end_minutes
                              << " is an invalid end time.\n";
                    return false;
                  }
                }
                else
                {
                  std::cout << "Error: Unable to get a valid end time.\n";
                  return false;
                }
              }
              else
              {
                std::cout << "Error: Unable to get a valid start time.\n";
                std::cout << "Error: " << start_hour << ":" << start_minutes
                          << " is an invalid start time.\n";
                return false;
              }
            }
            else
            {
              std::cout << "Error: Unable to get a valid start time.\n";
              return false;
            }
          }
          else
          {
            std::cout << "Invalid weekly schedule symbol " << schedule << "\n";
            return false;
          }
        }
        else
        {
          std::cout << "Error: Unable to get a weekly schedule.\n";
          return false;
        }
      }
      else
      {
        std::cout << "Error: Unable to get a location.\n";
        return false;
      }
    }
    else
    {
      return true;
    }
  }

  in_file.close();

  return true;
}

int main()
{
  bool valid_file;
  std::string file_name;

  std::cout << "Welcome to Tuffy Scheduler!\n";
  std::cout << "Please enter the file name containing the list of classes: ";
  std::cin >> file_name;

  valid_file = load_file(file_name);

  if (valid_file)
  {
    std::cout << "Valid file.\n";
  }
  else
  {
    std::cout << "Invalid file.\n";
  }

  std::cout << "Thank you for using Tuffy Scheduler.\n";

  return 0;
}
