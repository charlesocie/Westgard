//
// Created by charles.socie on 14/03/2018.
//

#ifndef WESTGARDBRICK_EUPDATERESULT_H
#define WESTGARDBRICK_EUPDATERESULT_H



/**
 * @defgroup EUpdateResult
 * @details result of a file's Update can take 7 differents values :
 *  - Update_Ok if the update succeed
 *  - Failed_File_Missing if the setting file is missing
 *  - Failed_Rule_Missing if the updated rule is missing in the file
 *  - Failed_File_Corrupt if the updated rule has something missing
 *  - Failed_Value_Out_Of_Range if the value to affect to a Parameterisable rule is not in the range (1 to 50)
 *  - Failed_Value_Non_Modifiable if the user try to affect a value to a non Parameterisable rule

 *
 */
enum EUpdateResult {
    UPDATE_OK,
    FAILED_FILE_MISSING,
    FAILED_RULE_MISSING,
    FAILED_FILE_CORRUPT,
    FAILED_VALUE_OUT_OF_RANGE,
    FAILED_VALUE_NON_MODIFIABLE,
	UPDATE_OK_RELOAD
};

#endif //WESTGARDBRICK_EUPDATERESULT_H
