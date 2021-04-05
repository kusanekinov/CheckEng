#pragma once
#include <QVariant>
#include <QComboBox>

/** \namespace gt::cb */
namespace gt::cb {

/**
 * \code
    gt::cb::setCurrent(m_switcher.ui()->m_type, type);
 * \endcode
**/
template<class T>
static inline bool setCurrent(QComboBox* const box, T val) noexcept {
    int index = -1;
    index = box->findData(QVariant::fromValue<T>(val));
    if(index == -1) return false;
    box->setCurrentIndex(index);
    return true;
}

/**
 * \code
    item.setType(gt::cb::current<item_t::type_t>((*ui)->m_type));
    auto const type = gt::cb::current<MuscleType>((*ui)->m_muscle);
 * \endcode
**/
template<class T>
static inline T current(QComboBox const* const box) noexcept {
    return box->currentData().value<T>();
}
} // end namespace gt::cb
