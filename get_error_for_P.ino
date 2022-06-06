int GetError() // return value of P ~ error
{
  static int prev_error = 0;
  switch (HighSignalCount()) {
    case 0: {
        long long int value_time = millis() - sys_start;
        if ((value_time < 9000) && (value_time > 5000)) {
          if ((Motor[0] > Motor[1] + 50) || (Motor[1] > Motor[0] + 50)) {
            back();
            long long int start_temp_time = millis();
            while (millis() - start_temp_time < 10);
          }
        }
        //    else {
        //      temp_speed = 170;
        //    }
        if (prev_error == 0) {
          return 0;
        } else if ((prev_error == 4) || (prev_error == 5)) {
          prev_error = 5;
          return 5;
        } else if ((prev_error == -4) || (prev_error == -5)) {
          prev_error = -5;
          return -5;
        } else {
          return prev_error;
        }
      }

    case 1:
      {
        for (int i = 0; i < 5; i++)
        {
          if (Line[i])
          {
            switch (i)
            {
              case 0:
                {
                  prev_error = -4;
                  return -4;
                  break;
                }
              case 1:
                {
                  prev_error = -2;
                  return -2;
                  break;
                }
              case 2:
                {
                  prev_error = 0;
                  return 0;
                  break;
                }
              case 3:
                {
                  prev_error = 2;
                  return 2;
                  break;
                }
              case 4:
                {
                  prev_error = 4;
                  return 4;
                  break;
                }
              default:
                {
                  return prev_error;
                  break;
                }
            } // sw
            break;
          } // if
        }   // for
        break;
      }
    case 2:
      {
        if (Line[0] && Line[1])
        {
          prev_error = -3;
          return -3;
        }
        else if (Line[1] && Line[2])
        {
          prev_error = -1;
          return -1;
        }
        else if (Line[2] && Line[3])
        {
          prev_error = 1;
          return 1;
        }
        else if (Line[3] && Line[4])
        {
          prev_error = 3;
          return 3;
        }
        else
          return prev_error;
        break;
      }
    case 3:
      {
        if (Line[1] && Line[2] && Line[3])
        {
          prev_error = 0;
          return 0;
        }
        else if (Line[0] && Line[1] && Line[2])
        {
          prev_error = -5;
          return -5;
        }
        else if (Line[2] && Line[3] && Line[4])
        {
          prev_error = 5;
          return 5;
        }
        else
          return prev_error;
        break;
      }
    case 5:
      {
        prev_error = 0;
        return 0;
      }
    default:
      {
        return 0;
        break;
      }
  }
  return prev_error;
}
