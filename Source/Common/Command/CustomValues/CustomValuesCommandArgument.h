/*
  ==============================================================================

    CustomValuesCommandArgument.h
    Created: 22 Feb 2017 8:51:30am
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "Common/Processor/Multiplex/MultiplexTarget.h"
#include "Common/ParameterLink/ParameterLink.h"

class CustomValuesCommandArgument :
	public BaseItem,
	public MultiplexTarget
{
public:
	CustomValuesCommandArgument(const String& name = "arg", Parameter* p = nullptr, bool mappingEnabled = false, bool templateMode = false, Multiplex * multiplex = nullptr);
	virtual ~CustomValuesCommandArgument();

	Parameter * param;
	BoolParameter * editable;

	bool mappingEnabled;
	bool templateMode;

	std::unique_ptr<ParameterLink> paramLink;

	CustomValuesCommandArgument * linkedTemplate;
	WeakReference<Inspectable *> linkedTemplateRef;

	void linkToTemplate(CustomValuesCommandArgument * t);

	void updateParameterFromTemplate();

	void onExternalParameterValueChanged(Parameter * p) override;
	void onExternalParameterRangeChanged(Parameter* p) override;

	var getLinkedValue(int multiplexIndex);

	var getJSONData() override;
	void loadJSONDataInternal(var data) override;

	virtual String getTypeString() const override;

	InspectableEditor * getEditor(bool isRoot) override;

};