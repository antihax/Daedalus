#pragma once
#include "Engine/DeveloperSettings.h"
#include "Array.h"
#include "UnrealString.h"
#include "SubclassOf.h"
#include "UObject/Class.h"

#include "FGGameUserSettings.h"
#include "FGOptionsSettings.generated.h"

UENUM( BlueprintType )
enum class EOptionCategory : uint8
{
	OC_Gameplay					UMETA( DisplayName = "Gameplay" ),
	OC_Audio					UMETA( DisplayName = "Audio" ),
	OC_Video					UMETA( DisplayName = "Video" ),
	OC_Controls					UMETA( DisplayName = "Controls" ),
	OC_UserInterface			UMETA( DisplayName = "User Interface" )
};

UENUM( BlueprintType )
enum class EOptionType : uint8
{
	OT_Checkbox					UMETA( DisplayName = "Checkbox" ),
	OT_IntegerSelection			UMETA( DisplayName = "IntegerSelection" ),
	OT_FloatSelection			UMETA( DisplayName = "FloatSelection" ),
	OT_Slider					UMETA( DisplayName = "Slider" )
};

USTRUCT( BlueprintType )
struct FACTORYGAME_API FOptionRowData
{
	GENERATED_BODY()

public:
	FOptionRowData(){}

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	FString OptionName;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	EOptionType OptionType;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	FString ConsoleVariable;
	
	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	bool DefaultCheckBoxValue;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	float MinValue;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	float MaxValue;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	float MinDisplayValue;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	float MaxDisplayValue;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	int32 MaxFractionalDigits;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	bool ShowZeroAsOff;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	float DefaultSliderValue;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	TMap<FString, int32> IntegerSelectionValues;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	TMap<FString, float> FloatSelectionValues;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	FString DefaultSelectionValue;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	bool UpdateInstantly;

	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	bool RequireRestart;
	
	UPROPERTY( BlueprintReadWrite, EditAnywhere )
	FString Tooltip;
};

UCLASS( config = Game, defaultconfig, meta = ( DisplayName = "Satisfactory User Options" ) )
class FACTORYGAME_API UFGOptionsSettings : public UDeveloperSettings
{
	GENERATED_BODY()

#if WITH_EDITOR
	virtual void PostEditChangeProperty( FPropertyChangedEvent& PropertyChangedEvent ) override
	{
		Super::PostEditChangeProperty( PropertyChangedEvent );
		if( UFGGameUserSettings* gameUserSettings = UFGGameUserSettings::GetFGGameUserSettings() )
		{
			gameUserSettings->SetupDefaultOptionsValues();
		}
	};
#endif
public:

	UPROPERTY( EditAnywhere, config, Category = "OptionRowData", meta = ( ToolTip = "" ) )
	TArray<FOptionRowData> mGameplayOptions;

	UPROPERTY( EditAnywhere, config, Category = "OptionRowData", meta = ( ToolTip = "" ) )
	TArray<FOptionRowData> mAudioOptions;

	UPROPERTY( EditAnywhere, config, Category = "OptionRowData", meta = ( ToolTip = "" ) )
	TArray<FOptionRowData> mVideoOptions;

	UPROPERTY( EditAnywhere, config, Category = "OptionRowData", meta = ( ToolTip = "" ) )
	TArray<FOptionRowData> mControlsOptions;

	UPROPERTY( EditAnywhere, config, Category = "OptionRowData", meta = ( ToolTip = "" ) )
	TArray<FOptionRowData> mUserInterfaceOptions;

	UPROPERTY( EditAnywhere, config, Category = "Widget Classes", meta = ( ToolTip = "" ) )
	TMap<EOptionType, TSubclassOf< class UFGOptionsValueController >> mOptionTypeWidgetsClasses;

	UPROPERTY( EditAnywhere, config, Category = "Widget Classes", meta = ( ToolTip = "" ) )
	TSubclassOf< class UFGDynamicOptionsRow > mOptionRowWidgetClass;

};
