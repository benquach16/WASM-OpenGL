#include "job.h"

Job::Job()
    : m_pipeline(nullptr)
    , m_parent(nullptr)
    , m_width(-1)
    , m_height(-1)
{
    m_pipeline = new GLPipeline;
}

Job::~Job()
{
    if (m_pipeline != nullptr) {
        delete m_pipeline;
    }

    m_pipeline = nullptr;
}

void Job::setVertexShader(const std::string& path)
{
    m_pipeline->addShader(path, GLProgram::eShaderType::Vertex);
}

void Job::setFragmentShader(const std::string& path)
{
    m_pipeline->addShader(path, GLProgram::eShaderType::Fragment);
}

void Job::run()
{
    if (m_pipeline == nullptr) {
        return;
    }
    m_pipeline->bindPipeline();

    while (!m_queue.empty()) {
        auto object = m_queue.front();
        m_queue.pop();
    }
}
