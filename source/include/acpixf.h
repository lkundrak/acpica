
/******************************************************************************
 * 
 * Name: acpisubsys.h - external interfaces to the ACPI subsystem
 *
 *****************************************************************************/

/******************************************************************************
 *
 * 1. Copyright Notice
 *
 * Some or all of this work - Copyright (c) 1999, Intel Corp.  All rights
 * reserved.
 *
 * 2. License
 *
 * 2.1. This is your license from Intel Corp. under its intellectual property
 * rights.  You may have additional license terms from the party that provided
 * you this software, covering your right to use that party's intellectual
 * property rights.
 *
 * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a
 * copy of the source code appearing in this file ("Covered Code") an
 * irrevocable, perpetual, worldwide license under Intel's copyrights in the
 * base code distributed originally by Intel ("Original Intel Code") to copy,
 * make derivatives, distribute, use and display any portion of the Covered
 * Code in any form, with the right to sublicense such rights; and
 *
 * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent
 * license (with the right to sublicense), under only those claims of Intel
 * patents that are infringed by the Original Intel Code, to make, use, sell,
 * offer to sell, and import the Covered Code and derivative works thereof
 * solely to the minimum extent necessary to exercise the above copyright
 * license, and in no event shall the patent license extend to any additions
 * to or modifications of the Original Intel Code.  No other license or right
 * is granted directly or by implication, estoppel or otherwise;
 *
 * The above copyright and patent license is granted only if the following
 * conditions are met:
 *
 * 3. Conditions 
 *
 * 3.1. Redistribution of Source with Rights to Further Distribute Source.  
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification with rights to further distribute source must include
 * the above Copyright Notice, the above License, this list of Conditions,
 * and the following Disclaimer and Export Compliance provision.  In addition,
 * Licensee must cause all Covered Code to which Licensee contributes to
 * contain a file documenting the changes Licensee made to create that Covered
 * Code and the date of any change.  Licensee must include in that file the
 * documentation of any changes made by any predecessor Licensee.  Licensee 
 * must include a prominent statement that the modification is derived,
 * directly or indirectly, from Original Intel Code.
 *
 * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification without rights to further distribute source must
 * include the following Disclaimer and Export Compliance provision in the
 * documentation and/or other materials provided with distribution.  In
 * addition, Licensee may not authorize further sublicense of source of any
 * portion of the Covered Code, and must include terms to the effect that the
 * license from Licensee to its licensee is limited to the intellectual
 * property embodied in the software Licensee provides to its licensee, and
 * not to intellectual property embodied in modifications its licensee may
 * make.
 *
 * 3.3. Redistribution of Executable. Redistribution in executable form of any
 * substantial portion of the Covered Code or modification must reproduce the
 * above Copyright Notice, and the following Disclaimer and Export Compliance
 * provision in the documentation and/or other materials provided with the
 * distribution.
 *
 * 3.4. Intel retains all right, title, and interest in and to the Original
 * Intel Code.
 *
 * 3.5. Neither the name Intel nor any other trademark owned or controlled by
 * Intel shall be used in advertising or otherwise to promote the sale, use or
 * other dealings in products derived from or relating to the Covered Code
 * without prior written authorization from Intel.
 *
 * 4. Disclaimer and Export Compliance
 *
 * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED
 * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE
 * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,
 * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY
 * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A
 * PARTICULAR PURPOSE. 
 *
 * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES
 * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR
 * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,
 * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY
 * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL
 * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS
 * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY
 * LIMITED REMEDY.
 *
 * 4.3. Licensee shall not export, either directly or indirectly, any of this
 * software or system incorporating such software without first obtaining any
 * required license or other approval from the U. S. Department of Commerce or
 * any other agency or department of the United States Government.  In the
 * event Licensee exports any such software from the United States or
 * re-exports any such software from a foreign destination, Licensee shall
 * ensure that the distribution and export/re-export of the software is in
 * compliance with all laws, regulations, orders, or other restrictions of the
 * U.S. Export Administration Regulations. Licensee agrees that neither it nor
 * any of its subsidiaries will export/re-export any technical data, process,
 * software, or service, directly or indirectly, to any country for which the
 * United States government or any agency thereof requires an export license,
 * other governmental approval, or letter of assurance, without first obtaining
 * such license, approval or letter.
 *
 *****************************************************************************/


#ifndef __ACPISUBSYS_H__
#define __ACPISUBSYS_H__

#include <acpitypes.h>
#include <acpitables.h>


/*
 * Global interfaces
 */

ACPI_STATUS
AcpiInitialize (
    void);

ACPI_STATUS
AcpiTerminate (
    void);

ACPI_STATUS
AcpiEnable (
	void);

ACPI_STATUS
AcpiDisable (
    void);

ACPI_STATUS
AcpiGetSystemInfo(
    ACPI_BUFFER             *RetBuffer);


/*
 * ACPI table manipulation interfaces
 */

ACPI_STATUS
AcpiLoadFirmwareTables (
    void);

ACPI_STATUS
AcpiLoadTable (
    ACPI_TABLE_HEADER       *TablePtr);

ACPI_STATUS
AcpiUnloadTable (
    ACPI_TABLE_TYPE         TableType);

ACPI_STATUS
AcpiGetTableHeader (
    ACPI_TABLE_TYPE         TableType,
    ACPI_TABLE_HEADER       *OutTableHeader);

ACPI_STATUS
AcpiGetTable (
    ACPI_TABLE_TYPE         TableType,
    ACPI_BUFFER             *RetBuffer);


/*
 * Namespace and name interfaces
 */

ACPI_STATUS
AcpiLoadNamespace (
    void);

ACPI_STATUS
AcpiWalkNamespace (
    ACPI_OBJECT_TYPE        Type, 
    ACPI_HANDLE             StartObject, 
    UINT32                  MaxDepth,
    void *                  (* UserFunction)(ACPI_HANDLE, UINT32, void *), 
    void                    *Context, 
    void *                  *ReturnValue);

ACPI_STATUS
AcpiNameToHandle (
    ACPI_HANDLE             Parent, 
    ACPI_NAME               Name,
    ACPI_HANDLE             *OutHandle);

ACPI_STATUS
AcpiHandleToName (
    ACPI_HANDLE             Handle,
    ACPI_NAME               *RetName);

ACPI_STATUS
AcpiPathnameToHandle (
    ACPI_STRING             Pathname,
    ACPI_HANDLE             *OutHandle);

ACPI_STATUS
AcpiHandleToPathname (
    ACPI_HANDLE             Handle,
    ACPI_BUFFER             *OutPathBuffer);


/* 
 * Object manipulation and enumeration
 */

ACPI_STATUS
AcpiEvaluateObject (
    ACPI_HANDLE             Object, 
    ACPI_STRING             Pathname, 
    ACPI_OBJECT_LIST        *ParameterObjects,
    ACPI_BUFFER             *ReturnObjectBuffer);

ACPI_STATUS
AcpiGetDeviceInfo (
    ACPI_HANDLE             Device, 
    ACPI_DEVICE_INFO        *Info);

ACPI_STATUS
AcpiGetNextObject (
    ACPI_OBJECT_TYPE        Type, 
    ACPI_HANDLE             Parent, 
    ACPI_HANDLE             Child,
    ACPI_HANDLE             *OutHandle);

ACPI_STATUS 
AcpiGetType (
    ACPI_HANDLE             Object,
    ACPI_OBJECT_TYPE        *OutType);

ACPI_STATUS
AcpiGetParent (
    ACPI_HANDLE             Object,
    ACPI_HANDLE             *OutHandle);


/*
 * Event handler interfaces
 */

ACPI_STATUS
AcpiInstallFixedEventHandler (
    ACPI_EVENT_TYPE         Event,
    FIXED_EVENT_HANDLER     Handler,
    void                    *Context);
    
ACPI_STATUS
AcpiRemoveFixedEventHandler (
    ACPI_EVENT_TYPE         Event,
    FIXED_EVENT_HANDLER     Handler);

ACPI_STATUS
AcpiInstallGpeHandler (
    UINT32                  GpeNumber, 
    GPE_HANDLER             Handler, 
    void                    *Context);

ACPI_STATUS
AcpiRemoveGpeHandler (
    UINT32                  GpeNumber, 
    GPE_HANDLER             Handler);

ACPI_STATUS
AcpiInstallNotifyHandler (
    ACPI_HANDLE             Device, 
    NOTIFY_HANDLER          Handler, 
    void                    *Context);

ACPI_STATUS
AcpiRemoveNotifyHandler (
    ACPI_HANDLE             Device, 
    NOTIFY_HANDLER          Handler);

ACPI_STATUS
AcpiInstallAddressSpaceHandler (
    UINT32                  SpaceId, 
    ADDRESS_SPACE_HANDLER   Handler, 
    void                    *Context);

ACPI_STATUS
AcpiRemoveAddressSpaceHandler (
    UINT32                  SpaceId, 
    ADDRESS_SPACE_HANDLER   Handler);


/*
 * Resource interfaces
 */

ACPI_STATUS
AcpiGetCurrentResources(
    ACPI_HANDLE             DeviceHandle,
    ACPI_BUFFER             *RetBuffer);

ACPI_STATUS
AcpiGetPossibleResources(
    ACPI_HANDLE             DeviceHandle,
    ACPI_BUFFER             *RetBuffer);

ACPI_STATUS
AcpiSetCurrentResources (
    ACPI_HANDLE             DeviceHandle,
    ACPI_BUFFER             *InBuffer);

ACPI_STATUS
AcpiGetIRQRoutingTable  (
    ACPI_HANDLE             BusDeviceHandle, 
    ACPI_BUFFER             *RetBuffer);


/*
 * Hardware (ACPI device) interfaces
 */

ACPI_STATUS
AcpiSetFirmwareWakingVector (
    void                    *PhysicalAddress);

ACPI_STATUS
AcpiGetFirmwareWakingVector (
    void                    **PhysicalAddress);

ACPI_STATUS 
AcpiSystemSleepStateSupported (
    UINT8                   SleepState,
    BOOLEAN					*Supported);

ACPI_STATUS
AcpiEnterSystemSleepState (
    UINT8                   SleepState);



#endif /* ACPISUBSYS_H */
