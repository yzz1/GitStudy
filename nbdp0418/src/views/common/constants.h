#ifndef CONSTANTS_H
#define CONSTANTS_H

// screen size
#define  SCREEN_SIZE_WIDTH    800
#define  SCREEN_SIZE_HEIGHT   600

//common string
#define  COMMON_MODLE_NAME   "Modle"
#define  COMMON_MODLE_OK   "OK"
#define  COMMON_MODLE_EDIT   "Edit"
#define  COMMON_MODLE_NEW   "New"
#define  COMMON_MODLE_OK   "OK"
#define  COMMON_MODLE_CANCEL  "Cancel"
#define  COMMON_DATETIME_FORMAT  "MM/dd/yyyy hh:mm"
#define  COMMON_UUID  "UUID"
#define  COMMON_OWER_INDIVIDUAL "I"
#define  COMMON_OWER_STATION "S"
#define  COMMON_OWER_MANUAL "M"
#define  COMMON_OWER_SCANGROUP "G"

// contacts  station view
#define CONTACTS_STATION_VIEW_NAME   "contactsStaViewWidget"
#define CONTACTS_STATION_EDIT_NAME  "contacts_station_edit_view"
#define CONTACTS_STATION_MODLE_NAME   "Modle"
#define CONTACTS_STATION_MODLE_EDIT   "Edit"
#define CONTACTS_STATION_MODLE_NEW   "New"
#define CONTACTS_STATION_MODLE_OK   "OK"
#define CONTACTS_STATION_MODLE_CANCEL  "Cancel"
#define CONTACTS_STATION_UUID   "UUID"
#define CONTACTS_STATION_NAME   "Name"
#define CONTACTS_STATION_CALLSIGN  "CallSign"
#define CONTACTS_STATION_COUNTRY  "Country"
#define CONTACTS_STATION_CALLCODE "CallCode"
#define CONTACTS_STATION_CREATEDATETIME "CreateDateTime"
#define CONTACTS_STATION_UPDATEDATETIME "UpdateDateTime"
#define CONTACTS_STATION_FREQUENCYS "frequencys"
#define CONTACTS_STATION_MAX_DISPLAY_DATA 20
#define CONTACTS_CALLCODE_MAXLEN   9
#define CONTACTS_NAME_MAXLEN   15
#define CONTACTS_CALLSIGN_MAXLEN   6
#define CONTACTS_COUNTRY_MAXLEN  15

#define HOME_VIEW_NAME  "homeWidget"
#define CALL_VIEW_NAME  "callWidget"
#define INDIVIDUAL_SELECT_VIEW "individual_select_view"
#define STATION_SELECT_VIEW "station_select_view"
#define MANUAL_FREQUENCY_VIEW "manual_frequency_view"
#define FREQUENCY_VIEW "requency_view"
#define CALL_OR_RECEIVE "callOrReceive"
#define CALL_COMMUNICATION_VIEW  "Call_Communication_view"

//contacts invididual view
#define CONTACTS_INDIVIDUAL_VIEW "contacts_individual_view"
#define CONTACTS_INDIVIDUAL_EDIT_NAME  "contacts_individual_edit_view"
#define CONTACTS_INDIVIDUAL_MODLE_NAME   "Modle"
#define CONTACTS_INDIVIDUAL_MODLE_EDIT   "Edit"
#define CONTACTS_INDIVIDUAL_MODLE_NEW   "New"
#define CONTACTS_INDIVIDUAL_MODLE_OK   "OK"
#define CONTACTS_INDIVIDUAL_MODLE_CANCEL  "Cancel"
#define CONTACTS_INDIVIDUAL_UUID   "UUID"
#define CONTACTS_INDIVIDUAL_NAME   "Name"

#define MESSAGES_CONTENT "messages_content"


//Manager_Phrasebook_show_view
#define MANAGER_PHRASEBOOK_UUID   "UUID"
#define MANAGER_PHRASEBOOK_NO   "No"
#define MANAGER_PHRASEBOOK_CREATEDATETIME "CreateDateTime"
#define MANAGER_PHRASEBOOK_UPDATEDATETIME "UpdateDateTime"
#define MANAGER_PHRASEBOOK_CONTENT "Content"

//Manager_Macro_show_view
#define MANAGER_MACRO_UUID   "UUID"
#define MANAGER_MACRO_NO   "No"
#define MANAGER_MACRO_CREATEDATETIME "CreateDateTime"
#define MANAGER_MACRO_UPDATEDATETIME "UpdateDateTime"
#define MANAGER_MACRO_NAME "Name"
namespace Constants {

typedef enum {
    BUTTON_FIRST,
    BUTTON_SCALED,
    BUTTON_ENTER,
    BUTTON_LEAVE,
    BUTTON_PRESSED,
    BUTTON_DISABLE
}BUTTONSTATUS;

static const char CONFIGFILENAME[] = "config.xml";

const char IMAGE_PATH[] = ":/images/";
const char NORMAL_ICON_SUFFIX[] = "_normal";
const char HOVER_ICON_SUFFIX[] = "_hover";
const char PRESSED_ICON_SUFFIX[] = "_normal";

// home view
const char CALLBTN_NAME[] = "callBtn";
const char CALLBTN_ICON_NAME[] = "menu_call";
const char CALLBTN_DISPLAY_NAME[] = QT_TR_NOOP("&Call");

const char CONTACTSBTN_NAME[] = "contactsBtn";
const char CONTACTSBTN_ICON_NAME[] = "menu_contacts";
const char CONTACTSBTN_DISPLAY_NAME[] = QT_TR_NOOP("Co&ntacts");

const char MESSAGESBTN_NAME[] = "messagesBtn";
const char MESSAGESBTN_ICON_NAME[] = "menu_message";
const char MESSAGESBTN_DISPLAY_NAME[] = QT_TR_NOOP("M&essages");

const char SCANBTN_NAME[] = "scanBtn";
const char SCANBTN_ICON_NAME[] = "menu_scan";
const char SCANBTN_DISPLAY_NAME[] = QT_TR_NOOP("&Scan");

const char MANAGEBTN_NAME[] = "manageBtn";
const char MANAGEBTN_ICON_NAME[] = "menu_manange";
const char MANAGEBTN_DISPLAY_NAME[] = QT_TR_NOOP("&Manage");

const char SYSTEMBTN_NAME[] = "systemBtn";
const char SYSTEMBTN_ICON_NAME[] = "menu_system";
const char SYSTEMBTN_DISPLAY_NAME[] = QT_TR_NOOP("Sys&tem");


// call view
//const char  CALL_SET_CALLRECEIVE[] =  "CALLRECEIVE";
const char  CALL_SET_CALLRECEIVE_CALL[] =  "1";
const char  CALL_SET_CALLRECEIVE_RECEIVE[] =  "0";
const char  CALL_SET_CALL_MODE[] =  "CallMode";
const char  CALL_SET_OWNER[] =  "Ower";
const char  CALL_SET_MODE_ARQ[] =  "ARQ";
const char  CALL_SET_MODE_SFEC[] =  "SFEC";
const char  CALL_SET_MODE_BFEC[] =  "BFEC";

// MessagesListView
const char MESSAEGS_LIST_VIEW_NAME[] = "messages_list_view";
const char MESSAEGS_LIST_TITLE_INBOX[] =  QT_TR_NOOP("MESSAGES  INBOX");
const char MESSAEGS_LIST_TITLE_OUTBOX[] =  QT_TR_NOOP("MESSAGES  OUTBOX");
const char MESSAEGS_LIST_TABLE_NAME[] =  "Message";
const char MESSAEGS_LIST_COL_UUID[] =  "UUID";
const char MESSAEGS_LIST_COL_CHECKFLAG[] =  "checkFlag";
const char MESSAEGS_LIST_COL_SHOWPIX[] =  "showPix";
const char MESSAEGS_LIST_COL_INOUT[] =  "InputOutput";
const char MESSAEGS_LIST_COL_CALLCODE[] =  "CallCode";
const char MESSAEGS_LIST_COL_MODE[] =  "CallMode";
const char MESSAEGS_LIST_COL_SIGN[] =  "CallSign";
const char MESSAEGS_LIST_COL_COUNTRY[] =  "Country";
const char MESSAEGS_LIST_COL_NAME[] =  "Name";
const char MESSAEGS_LIST_COL_TX[] =  "Tx";
const char MESSAEGS_LIST_COL_RX[] =  "Rx";
const char MESSAEGS_LIST_COL_CHANNEL[] =  "Channel";
const char MESSAEGS_LIST_COL_TIMESTART[] =  "MsgDateTimeStart";
const char MESSAEGS_LIST_COL_TIMEEND[] =  "MsgDateTimeEnd";
const char MESSAEGS_LIST_INOUT_I[] =  "I";
const char MESSAEGS_LIST_INOUT_O[] =  "O";
const char MESSAEGS_LIST_MESSAGE_READED_FLAG[] =  "Y";
const char MESSAEGS_LIST_MESSAGE_UNREAD_FLAG[] =  "N";

typedef enum
{
    MESSAEGS_INDEX_UUID,
    MESSAEGS_INDEX_CHECKFLAG,
    MESSAEGS_INDEX_SHOWPIX,
    MESSAEGS_INDEX_INOUT,
    MESSAEGS_INDEX_CALLCODE,
    MESSAEGS_INDEX_MODE,
    MESSAEGS_INDEX_SIGN,
    MESSAEGS_INDEX_COUNTRY,
    MESSAEGS_INDEX_NAME,
    MESSAEGS_INDEX_TX,
    MESSAEGS_INDEX_RX,
    MESSAEGS_INDEX_CHANNEL,
    MESSAEGS_INDEX_TIMESTART,
    MESSAEGS_INDEX_TIMEEND
} MESSAEGS_INDEX ;

// messages_show_view
const char MESSAEGS_SHOW_VIEW_NAME[] = "messages_show_view";
const char MESSAEGS_SHOW_TABLE_NAME[] =  "MessageDetail";
const char MESSAEGS_SHOW_COL_UUID[] =  "UUID";
const char MESSAEGS_SHOW_COL_FKEY[] =  "FKey";
const char MESSAEGS_SHOW_COL_SENDSTATUS[] =  "SendStatus";
const char MESSAEGS_SHOW_COL_INOUT[] =  "InputOutput";
const char MESSAEGS_SHOW_COL_CONTENT[] =  "Content";
const char MESSAEGS_SHOW_COL_CDATETIME[] =  "CommunicationDateTime";
typedef enum
{
    MESSAEGSDETAIL_INDEX_UUID,
    MESSAEGSDETAIL_INDEX_FKEY,
    MESSAEGSDETAIL_INDEX_INOUT,
    MESSAEGSDETAIL_INDEX_CONTENT,
    MESSAEGSDETAIL_INDEX_CDATETIME
} MESSAEGSDETAIL_INDEX ;

//Call_Communication_view
const char COMMUMESSAEGS_DETAIL_TABLE_NAME[] =  "CommuMessageDetail";
const char COMMUMESSAEGS_SENDSTATUS_FALSE[] =  "FALSE";
const char COMMUMESSAEGS_SENDSTATUS_TRUE[] =  "TRUE";
const char COMMUMESSAEGS_SENDSTATUS_SEND[] =  "SEND";
const char COMMUMESSAEGS_MACRO_WRU[] =  "WRU";
const char COMMUMESSAEGS_MACRO_OVER_SEND[] =  "+?";
const char COMMUMESSAEGS_MACRO_OVER_SHOW[] =  "[OVER]";
const char COMMUMESSAEGS_MACRO_BREAK_SEND[] =  "BRK+";
const char COMMUMESSAEGS_MACRO_BREAK_SHOW[] =  "[Break]";
const int  COMMUMESSAEGS_SHOW_LENGH =  60;
const int  MAXINPUTSIZE = 60;
const int   NAME_LABEL_LENGTH = 9;
const int   PHRASEBOOK_SHOW_LENGH=  15;
const int   COMMUMESSAEGS_SHOW_ROW_HIGHT =  30;
typedef enum
{
    COMMUMESSAGEDETAILl_INDEX_UUID,
    COMMUMESSAGEDETAILl_INDEX_FKEY,
    COMMUMESSAGEDETAILl_INDEX_INOUT,
    COMMUMESSAGEDETAILl_INDEX_CONTENT,
    COMMUMESSAGEDETAILl_INDEX_CDATETIME,
    COMMUMESSAGEDETAILl_INDEX_SENDSTATUS
} COMMUMESSAGEDETAILl_INDEX ;

//Manager_File_List_view
//const char MANAGER_FILE[] = "manager_file_view";
const char MANAGER_FILE[]="manager_file";
const char FILe_LIST_TABLE_NAME[] =  "file";
const char FILe_LIST_COL_UUID[] =  "UUID";
const char FILe_LIST_COL_SHOWPIX[] =  "showPix";
const char FILe_LIST_COL_NAME[] =  "Name";
const char FILe_LIST_COL_CONTENT[] =  "Content";
const char FILe_LIST__COL_CDATETIME[] =  "CreateDateTime";
const char FILe_LIST__COL_UDATETIME[] =  "UpdateDateTime";
typedef enum
{
    FILe_INDEX_UUID,
    FILe_INDEX_SHOWPIX,
    FILe_INDEX_NAME,
    FILe_INDEX_CONTENT,
    FILe_INDEX_CDATETIME,
    FILe_INDEX_UDATETIME,
} FILE_INDEX ;

typedef enum
{
    FILE_FOCUS_TABLEVIEW,
    FILE_FOCUS_NEW,
    FILE_FOCUS_EDIT,
    FILE_FOCUS_DELETE,
    FILE_FOCUS_RENAME,
    FILE_FOCUS_OPTION,
    FILE_FOCUS_EXPORT,
    FILE_FOCUS_IMPORT,
    FILE_FOCUS_HOME,
    FILE_FOCUS_FILE,
    FILE_FOCUS_MACRO,
    FILE_FOCUS_PHRASEBOOK,
} FILE_FOCUS ;

//manager file   edit
const char MANAGER_FILE_TITLE[] =  QT_TR_NOOP("MANAGER FILE");
const char MANAGER_FILE_EDIT_VIEW[]="manager_file_edit_view";
const char MANAGER_FILE_EDIT_VIEW_TITLE[] =  QT_TR_NOOP("NEW FILE");
const char MANAGER_FILE_NEW[] =  "New";
const char MANAGER_FILE_EDIT[] =  "Edit";
const char MANAGER_MODLE_NAME[]="Modle";
const char MANAGER_FILE_UUID[] =  "UUID";
const int    MANAGER_FILE_EDIT_SIZE =  22;

//Manager_Macro_List_view
const char MANAGER_MACRO[]="manager_macro";
const char MANAGER_MACRO_TITLE[] =  QT_TR_NOOP("MANAGER MACRO");
const char MACRO_LIST_TABLE_NAME[] =  "Macro";
const char MACRO_LIST_COL_UUID[] =  "UUID";
const char MACRO_LIST_COL_SHOWPIX[] =  "showPix";
const char MACRO_LIST_COL_NO[] =  "No";
const char MACRO_LIST_COL_NAME[] =  "Name";
const char MACRO_LIST__COL_CDATETIME[] =  "CreateDateTime";
const char MACRO_LIST__COL_UDATETIME[] =  "UpdateDateTime";
const int    MACROMAX_EDIT_SIZE =  10;
typedef enum
{
    MACRO_INDEX_UUID,
    MACRO_INDEX_SHOWPIX,
    MACRO_INDEX_NO,
    MACRO_INDEX_NAME,
    MACRO_INDEX_CDATETIME,
    MACRO_INDEX_UDATETIME,
} MACRO_INDEX ;

//Manager_Phrasebook_List_view
const char MANAGER_PHRASEBOOK[]="manager_phrasebook";
const char MANAGER_PHRASEBOOK_TITLE[] =  QT_TR_NOOP("MANAGER PHRASEBOOK");
const char PHRASEBOOK_LIST_TABLE_NAME[] =  "Phrasebook";
const char PHRASEBOOK_LIST_COL_UUID[] =  "UUID";
const char PHRASEBOOK_LIST_COL_SHOWPIX[] =  "showPix";
const char PHRASEBOOK_LIST_COL_NO[] =  "No";
const char PHRASEBOOK_LIST_COL_CONTENT[] =  "Content";
const char PHRASEBOOK_LIST__COL_CDATETIME[] =  "CreateDateTime";
const char PHRASEBOOK_LIST__COL_UDATETIME[] =  "UpdateDateTime";
const char PHRASEBOOK_LIST_NODOT[] =  "No.";
const int    PHRASEBOOK_MAX_EDIT_SIZE =  50;
typedef enum
{
    PHRASEBOOK_INDEX_UUID,
    PHRASEBOOK_INDEX_SHOWPIX,
    PHRASEBOOK_INDEX_NO,
    PHRASEBOOK_INDEX_CONTENT,
    PHRASEBOOK_INDEX_CDATETIME,
    PHRASEBOOK_INDEX_UDATETIME,
} PHRASEBOOK_INDEX ;

//  system  setting
const char SYSTEM_SETTING_VIEW[] = "system_setting";
const char SYSTEM_SETTING_TITLE[] = QT_TR_NOOP("SYSTEM SETTING");
const char SYSTEM_SETTING_TABLE_NAME[] =  "setting";
#define SYSTEM_SETTING_DIGITCALLCODE   "digitcallcode"
#define SYSTEM_SETTING_MMSICODE "mmsicode"
#define SYSTEM_SETTING_ANSWERBACKCODE "answerbackcode"
#define SYSTEM_SETTING_SLAVEDELAY "slavedelay"
#define SYSTEM_SETTING_REALTIMEPRINT "realtimeprint"
#define SYSTEM_SETTING_LANGUAGE "language"
#define SYSTEM_SETTING_MODLE_NAME   "Modle"
#define SYSTEM_SETTING_MODLE_OK   "OK"
#define SYSTEM_SETTING_CANCEL  "Cancel"
#define SYSTEM_SETTING_PRINTMODE_REAL  "0"
#define SYSTEM_SETTING_PRINTMODE_PRINT  "1"
#define SYSTEM_SETTING_DIGITCALLCODELABEL  "4 or 5-digit Call Code:"
#define SYSTEM_SETTING_DIGITMMSICODELABEL  "9-digit MMSI Code:"
#define SYSTEM_SETTING_ANSWERBACKCODELABEL  "Answer Back Code:"


const char SCAN_VIEW_NAME[] = "scan_view";
const char SYSTEM_VIEW_NAME[] = "system_view";

//  system  test
const char SYSTEM_TEST_VIEW[] = "system_test";
const char SYSTEM_TEST_TITLE[] = QT_TR_NOOP("TEST");

//  system  about
const char SYSTEM_ABOUT_VIEW[] = "system_about";
const char SYSTEM_ABOUT_TITLE[] = QT_TR_NOOP("SYSTEM ABOUT");

//  system  identification setting
const char SYSTEM_IDENTIFICATION_SETTING_VIEW[] = "identification_setting";
const char SYSTEM_IDENTIFICATION_SETTING_TITLE[] = QT_TR_NOOP("IDENTIFICATION SETTING");

// scan group
#define SCAN_GROUP_VIEW  "scan_group_view"
#define SCAN_GROUP_MODLE_NAME   "Modle"
#define SCAN_GROUP_MODLE_EDIT   "Edit"
#define SCAN_GROUP_MODLE_NEW   "New"
#define SCAN_GROUP_MODLE_OK   "OK"
#define SCAN_GROUP_MODLE_CANCEL  "Cancel"
#define SCAN_GROUP_MAX_DISPLAY_DATA 20
const char SCAN_GROUP_TITLE[] = QT_TR_NOOP("SCAN GROUP");
const char SCAN_GROUP_UUID[] =  "UUID";
const char SCAN_GROUP_SHOWPIX[] =  "showPix";
const char SCAN_GROUP_GROUPNAME[] =  "GroupName";
const char SCAN_GROUP_DWELLTIME[] =  "DwellTime";
const char SCAN_GROUP_SCANMODE[] =  "ScanMode";
const char SCAN_GROUP_CDATETIME[] =  "CreateDateTime";
const char SCAN_GROUP_UDATETIME[] =  "UpdateDateTime";
typedef enum
{
    SCAN_GROUP_INDEX_UUID,
    SCAN_GROUP_INDEX_SHOWPIX,
    SCAN_GROUP_INDEX_GROUPNAME,
    SCAN_GROUP_INDEX_DWELLTIME,
    SCAN_GROUP_INDEX_SCANMODE,
    SCAN_GROUP_INDEX_CDATETIME,
    SCAN_GROUP_INDEX_UDATETIME,
} SCAN_GROUP_INDEX ;

// scan group edit
#define SCAN_GROUP_EDIT_VIEW  "scan_group_edit_view"
const char SCAN_GROUP__EDIT_TITLE[] = QT_TR_NOOP("EDIT SCAN GROUP");
const char SCAN_GROUP__NEW_TITLE[] = QT_TR_NOOP("NEW SCAN GROUP");


// scan frequency view
#define SCAN_FREQUENCY_VIEW  "scan_frequency_view"
const char SCAN_FREQUENCY_TITLE[] = QT_TR_NOOP("SCANNING FREQUENCY");

}
#endif // CONSTANTS_H
