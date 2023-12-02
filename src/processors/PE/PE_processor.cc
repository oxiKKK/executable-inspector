/***
*	executable-inspector developed by oxiKKK
*
*	Copyright (c) 2022-present, oxiKKK
*
*	For licensing information, see the "LICENSE" file
*	included in project root directory.
****/

CPEProcessor g_processor;

extern "C" EXPORT void* get_processor_factory()
{
	return reinterpret_cast<void*>(&g_processor);
}

bool CPEProcessor::process_file(const std::filesystem::path& filepath, EProcessOptions options)
{
	return false;
}

void CPEProcessor::render_gui()
{
	ImGui::Begin("PE processor");
	ImGui::Text("Hello world");
	ImGui::End();
}