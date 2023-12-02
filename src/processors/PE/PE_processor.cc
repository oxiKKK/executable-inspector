/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

#include "precompiled.h"

CPEProcessor g_processor;

extern "C" EXPORT void* get_processor_factory()
{
	return reinterpret_cast<void*>(&g_processor);
}

bool CPEProcessor::process_file(const std::filesystem::path& filepath, EProcessOptions options)
{
	m_reader = std::make_unique<ProcessedFileReader>(filepath);

	if (!process_dos_hdr())
	{
		con::error("couldn't process DOS header");
		return false;
	}

	return true;
}

void CPEProcessor::render_gui()
{
	ImGui::SetNextWindowSize({ 700, 700 }, ImGuiCond_FirstUseEver);
	ImGui::Begin("PE processor");

	if (ImGui::BeginTable("dos", 2, ImGuiTableFlags_None))
	{
		ImGui::TableSetupColumn("dos_0");
		ImGui::TableSetupColumn("dos_1");

		ImGui::TableNextColumn(); ImGui::TextWrapped("Magic");
		ImGui::TableNextColumn(); ImGui::TextWrapped(m_data.file_magic.name().c_str());

		ImGui::EndTable();
	}

	ImGui::End();
}