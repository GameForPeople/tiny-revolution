// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TINYREVOLUTION_WonSY_GameInstance_generated_h
#error "WonSY_GameInstance.generated.h already included, missing '#pragma once' in WonSY_GameInstance.h"
#endif
#define TINYREVOLUTION_WonSY_GameInstance_generated_h

#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndNetwork) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EndNetwork(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartNetwork) \
	{ \
		P_GET_UBOOL(Z_Param_isUsePublicIP); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartNetwork(Z_Param_isUsePublicIP); \
		P_NATIVE_END; \
	}


#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndNetwork) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EndNetwork(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartNetwork) \
	{ \
		P_GET_UBOOL(Z_Param_isUsePublicIP); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartNetwork(Z_Param_isUsePublicIP); \
		P_NATIVE_END; \
	}


#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWonSY_GameInstance(); \
	friend struct Z_Construct_UClass_UWonSY_GameInstance_Statics; \
public: \
	DECLARE_CLASS(UWonSY_GameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TinyRevolution"), NO_API) \
	DECLARE_SERIALIZER(UWonSY_GameInstance)


#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUWonSY_GameInstance(); \
	friend struct Z_Construct_UClass_UWonSY_GameInstance_Statics; \
public: \
	DECLARE_CLASS(UWonSY_GameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TinyRevolution"), NO_API) \
	DECLARE_SERIALIZER(UWonSY_GameInstance)


#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWonSY_GameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWonSY_GameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWonSY_GameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWonSY_GameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWonSY_GameInstance(UWonSY_GameInstance&&); \
	NO_API UWonSY_GameInstance(const UWonSY_GameInstance&); \
public:


#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWonSY_GameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWonSY_GameInstance(UWonSY_GameInstance&&); \
	NO_API UWonSY_GameInstance(const UWonSY_GameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWonSY_GameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWonSY_GameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWonSY_GameInstance)


#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_PRIVATE_PROPERTY_OFFSET
#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_18_PROLOG
#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_PRIVATE_PROPERTY_OFFSET \
	TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_RPC_WRAPPERS \
	TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_INCLASS \
	TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_PRIVATE_PROPERTY_OFFSET \
	TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_INCLASS_NO_PURE_DECLS \
	TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TINYREVOLUTION_API UClass* StaticClass<class UWonSY_GameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TinyRevolution_Source_TinyRevolution_WonSY_GameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
