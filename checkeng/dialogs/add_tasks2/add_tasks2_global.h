#pragma once

#if defined(ADD_TASKS2_DIALOG_LIBRARY)
    #define ADD_TASKS2_DIALOG_SHARED_EXPORT Q_DECL_EXPORT
#else
    #define ADD_TASKS2_DIALOG_SHARED_EXPORT Q_DECL_IMPORT
#endif

