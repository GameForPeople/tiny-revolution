// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TINYREVOLUTION_GM_Base_generated_h
#error "GM_Base.generated.h already included, missing '#pragma once' in GM_Base.h"
#endif
#define TINYREVOLUTION_GM_Base_generated_h

#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_RPC_WRAPPERS
#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGM_Base(); \
	friend struct Z_Construct_UClass_AGM_Base_Statics; \
public: \
	DECLARE_CLASS(AGM_Base, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TinyRevolution"), NO_API) \
	DECLARE_SERIALIZER(AGM_Base)


#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAGM_Base(); \
	friend struct Z_Construct_UClass_AGM_Base_Statics; \
public: \
	DECLARE_CLASS(AGM_Base, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TinyRevolution"), NO_API) \
	DECLARE_SERIALIZER(AGM_Base)


#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGM_Base(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGM_Base) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGM_Base); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGM_Base); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGM_Base(AGM_Base&&); \
	NO_API AGM_Base(const AGM_Base&); \
public:


#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGM_Base(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGM_Base(AGM_Base&&); \
	NO_API AGM_Base(const AGM_Base&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGM_Base); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGM_Base); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGM_Base)


#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_PRIVATE_PROPERTY_OFFSET
#define TinyRevolution_Source_TinyRevolution_GM_Base_h_12_PROLOG
#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TinyRevolution_Source_TinyRevolution_GM_Base_h_15_PRIVATE_PROPERTY_OFFSET \
	TinyRevolution_Source_TinyRevolution_GM_Base_h_15_RPC_WRAPPERS \
	TinyRevolution_Source_TinyRevolution_GM_Base_h_15_INCLASS \
	TinyRevolution_Source_TinyRevolution_GM_Base_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TinyRevolution_Source_TinyRevolution_GM_Base_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TinyRevolution_Source_TinyRevolution_GM_Base_h_15_PRIVATE_PROPERTY_OFFSET \
	TinyRevolution_Source_TinyRevolution_GM_Base_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TinyRevolution_Source_TinyRevolution_GM_Base_h_15_INCLASS_NO_PURE_DECLS \
	TinyRevolution_Source_TinyRevolution_GM_Base_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TINYREVOLUTION_API UClass* StaticClass<class AGM_Base>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TinyRevolution_Source_TinyRevolution_GM_Base_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
