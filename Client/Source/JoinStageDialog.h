/*
   Copyright (c) 2021 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include "JuceHeader.h"

#include "DataStore.h"
#include "SimpleTable.h"
#include "DSLookAndFeel.h"

#include "ServerInfo.h"

#include "ApplicationState.h"


#include <nlohmann/json.hpp>

class JoinStageDialog : public Component
{
public:
	static void showDialog(std::shared_ptr<DataStore> store);
	static void release();

	JoinStageDialog(std::shared_ptr<DataStore> store);
	virtual ~JoinStageDialog();

	virtual void resized() override;

	static bool isCurrentlyOpen();
	void setStages(std::vector<DigitalStage::Types::Stage> const& stages);

	void updateSelectedStage();

private:
	std::shared_ptr<DataStore> store_;
	std::vector<DigitalStage::Types::Stage> stagesInTable_;
	SimpleTable<std::vector<DigitalStage::Types::Stage>> stageTable_;
	std::optional<DigitalStage::Types::Stage> selectedStage_;
	TextButton joinButton_;

	DSLookAndFeel dsLookAndFeel_;

	std::vector<std::unique_ptr<ValueListener>> listeners_;
};
